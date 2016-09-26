/*
 * Copyright © 2012 Intel Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "cl_event.h"
#include "cl_context.h"
#include "cl_command_queue.h"
#include "cl_alloc.h"
#include <string.h>
#include <stdio.h>

LOCAL cl_int
cl_event_get_timestamp(cl_event event, cl_profiling_info param_name)
{
  // TODO:
  return CL_INVALID_VALUE;
}

LOCAL cl_ulong
cl_event_get_timestamp_delta(cl_ulong start_timestamp, cl_ulong end_timestamp)
{
  cl_ulong ret_val;

  if (end_timestamp > start_timestamp) {
    ret_val = end_timestamp - start_timestamp;
  } else {
    /*if start time stamp is greater than end timstamp then set ret value to max*/
    ret_val = ((cl_ulong)1 << 32);
  }

  return ret_val;
}

LOCAL cl_ulong
cl_event_get_start_timestamp(cl_event event)
{
  cl_ulong ret_val;

  ret_val = cl_event_get_timestamp_delta(event->timestamp[0], event->timestamp[2]);

  return ret_val;
}

LOCAL cl_ulong
cl_event_get_end_timestamp(cl_event event)
{
  cl_ulong ret_val;

  ret_val = cl_event_get_timestamp_delta(event->timestamp[0], event->timestamp[3]);

  return ret_val;
}

LOCAL void
cl_event_add_ref(cl_event event)
{
  assert(event);
  CL_OBJECT_INC_REF(event);
}

LOCAL cl_int
cl_event_get_status(cl_event event)
{
  cl_int ret;

  assert(event);
  CL_OBJECT_LOCK(event);
  ret = event->status;
  CL_OBJECT_UNLOCK(event);
  return ret;
}

static cl_event
cl_event_new(cl_context ctx, cl_command_queue queue, cl_command_type type,
             cl_uint num_events, cl_event *event_list)
{
  cl_event e = cl_calloc(1, sizeof(_cl_event));
  if (e == NULL)
    return NULL;

  CL_OBJECT_INIT_BASE(e, CL_OBJECT_EVENT_MAGIC);

  /* Append the event in the context event list */
  cl_context_add_event(ctx, e);
  e->queue = queue;

  list_init(&e->callbacks);
  list_init(&e->enqueue_node);

  assert(type >= CL_COMMAND_NDRANGE_KERNEL && type <= CL_COMMAND_FILL_IMAGE);
  e->event_type = type;
  if (type == CL_COMMAND_USER) {
    e->status = CL_SUBMITTED;
  } else {
    e->status = CL_QUEUED;
  }

  if (type == CL_COMMAND_USER) {
    assert(queue == NULL);
  }

  e->depend_events = event_list;
  e->depend_event_num = num_events;
  return e;
}

LOCAL void
cl_event_delete(cl_event event)
{
  int i;
  cl_event_user_callback cb;

  if (UNLIKELY(event == NULL))
    return;

  if (CL_OBJECT_DEC_REF(event) > 1)
    return;

  cl_enqueue_delete(&event->exec_data);

  assert(list_empty(&event->enqueue_node));

  if (event->depend_events) {
    assert(event->depend_event_num);
    for (i = 0; i < event->depend_event_num; i++) {
      cl_event_delete(event->depend_events[i]);
    }
    cl_free(event->depend_events);
  }

  /* Free all the callbacks. Last ref, no need to lock. */
  while (!list_empty(&event->callbacks)) {
    cb = list_entry(event->callbacks.next, _cl_event_user_callback, node);
    list_del(&cb->node);
    cl_free(cb);
  }

  /* Remove it from the list */
  assert(event->ctx);
  cl_context_remove_event(event->ctx, event);

  CL_OBJECT_DESTROY_BASE(event);
  cl_free(event);
}

LOCAL cl_event
cl_event_create(cl_context ctx, cl_command_queue queue, cl_uint num_events,
                const cl_event *event_list, cl_command_type type, cl_int *errcode_ret)
{
  cl_event e = NULL;
  cl_event *depend_events = NULL;
  cl_int err = CL_SUCCESS;
  cl_uint total_events = 0;
  int i;

  assert(ctx);

  do {
    if (event_list)
      assert(num_events);

    if (queue == NULL) {
      assert(type == CL_COMMAND_USER);
      assert(event_list == NULL);
      assert(num_events == 0);

      e = cl_event_new(ctx, queue, type, 0, NULL);
      if (e == NULL) {
        err = CL_OUT_OF_HOST_MEMORY;
        break;
      }
    } else {
      CL_OBJECT_LOCK(queue);
      total_events = queue->barrier_events_num + num_events;

      if (total_events) {
        depend_events = cl_calloc(total_events, sizeof(cl_event));
        if (depend_events == NULL) {
          CL_OBJECT_UNLOCK(queue);
          err = CL_OUT_OF_HOST_MEMORY;
          break;
        }
      }

      /* Add all the barrier events as depend events. */
      for (i = 0; i < queue->barrier_events_num; i++) {
        assert(CL_EVENT_IS_BARRIER(queue->barrier_events[i]));
        cl_event_add_ref(queue->barrier_events[i]);
        depend_events[num_events + i] = queue->barrier_events[i];
      }

      CL_OBJECT_UNLOCK(queue);

      for (i = 0; i < num_events; i++) {
        assert(event_list[i]);
        assert(event_list[i]->ctx == ctx);
        assert(CL_OBJECT_IS_EVENT(event_list[i]));
        cl_event_add_ref(event_list[i]);
        depend_events[i] = event_list[i];
      }

      if (depend_events)
        assert(total_events);

      e = cl_event_new(ctx, queue, type, total_events, depend_events);
      if (e == NULL) {
        err = CL_OUT_OF_HOST_MEMORY;
        break;
      }
      depend_events = NULL;
    }
  } while (0);

  if (err != CL_SUCCESS) {
    if (depend_events) {
      for (i = 0; i < total_events; i++) {
        cl_event_delete(depend_events[i]);
      }
      cl_free(depend_events);
    }

    // if set depend_events, must succeed.
    assert(e->depend_events == NULL);
    cl_event_delete(e);
  }

  if (errcode_ret)
    *errcode_ret = err;

  return e;
}

LOCAL cl_int
cl_event_set_callback(cl_event event, cl_int exec_type, cl_event_notify_cb pfn_notify, void *user_data)
{
  cl_int err = CL_SUCCESS;
  cl_event_user_callback cb;
  cl_bool exec_imm = CL_FALSE;

  assert(event);
  assert(pfn_notify);

  do {
    cb = cl_calloc(1, sizeof(_cl_event_user_callback));
    if (cb == NULL) {
      err = CL_OUT_OF_HOST_MEMORY;
      break;
    }

    list_init(&cb->node);
    cb->pfn_notify = pfn_notify;
    cb->user_data = user_data;
    cb->status = exec_type;
    cb->executed = CL_FALSE;

    CL_OBJECT_LOCK(event);
    if (event->status > exec_type) {
      list_add_tail(&cb->node, &event->callbacks);
      cb = NULL;
    } else {
      /* The state has already OK, call it immediately. */
      exec_imm = CL_TRUE;
    }
    CL_OBJECT_UNLOCK(event);

    if (exec_imm) {
      cb->pfn_notify(event, event->status, cb->user_data);
    }

  } while (0);

  if (cb)
    cl_free(cb);

  return err;
}

LOCAL cl_int
cl_event_set_status(cl_event event, cl_int status)
{
  list_head tmp_callbacks;
  list_head *n;
  list_head *pos;
  cl_bool notify_queue = CL_FALSE;
  cl_event_user_callback cb;

  assert(event);

  CL_OBJECT_LOCK(event);
  if (event->status <= CL_COMPLETE) { // Already set to error or completed
    CL_OBJECT_UNLOCK(event);
    return CL_INVALID_OPERATION;
  }

  if (CL_EVENT_IS_USER(event)) {
    assert(event->status != CL_RUNNING && event->status != CL_QUEUED);
  } else {
    assert(event->queue); // Must belong to some queue.
  }

  if (status >= event->status) { // Should never go back.
    CL_OBJECT_UNLOCK(event);
    return CL_INVALID_OPERATION;
  }

  event->status = status;

  /* Call all the callbacks. */
  if (!list_empty(&event->callbacks)) {
    do {
      status = event->status;
      list_init(&tmp_callbacks);
      list_replace(&event->callbacks, &tmp_callbacks);
      list_init(&event->callbacks);
      /* Call all the callbacks without lock. */
      CL_OBJECT_UNLOCK(event);

      list_for_each_safe(pos, n, &tmp_callbacks)
      {
        cb = list_entry(pos, _cl_event_user_callback, node);

        assert(cb->executed == CL_FALSE);

        if (cb->status < status)
          continue;

        list_del(&cb->node);
        cb->executed = CL_TRUE;
        cb->pfn_notify(event, status, cb->user_data);
        cl_free(cb);
      }

      CL_OBJECT_LOCK(event);

      // Set back the uncalled callbacks.
      list_splice_tail(&tmp_callbacks, &event->callbacks);

      /* Status may changed because we unlock. need to check again. */
    } while (status != event->status);
  }

  /*  Wakeup all the waiter for status change. */
  CL_OBJECT_NOTIFY_COND(event);

  if (event->status <= CL_COMPLETE) {
    notify_queue = CL_TRUE;
  }

  CL_OBJECT_UNLOCK(event);

  /* Need to notify all the command queue within the same context. */
  if (notify_queue) {
    cl_command_queue *q_list = NULL;
    cl_uint queue_num = 0;
    int i = 0;
    int cookie = 0;

    /*First, we need to remove it from queue's barrier list. */
    if (CL_EVENT_IS_BARRIER(event)) {
      assert(event->queue);
      cl_command_queue_remove_barrier_event(event->queue, event);
    }

    /* Then, notify all the queues within the same context. */
    CL_OBJECT_LOCK(event->ctx);
    do {
      queue_num = event->ctx->queue_num;
      cookie = event->ctx->queue_cookie;

      if (queue_num > 0) {
        q_list = cl_calloc(queue_num, sizeof(cl_command_queue));
        assert(q_list);
        i = 0;
        list_for_each(pos, &event->ctx->queues)
        {
          q_list[i] = (cl_command_queue)(list_entry(pos, _cl_base_object, node));
          assert(i < queue_num);
          i++;
        }

        CL_OBJECT_UNLOCK(event->ctx); // Update status without context lock.

        for (i = 0; i < queue_num; i++) {
          cl_command_queue_notify(q_list[i]);
        }

        CL_OBJECT_LOCK(event->ctx); // Lock again.
      } else {
        /* No queue? Just do nothing. */
      }

    } while (cookie != event->ctx->queue_cookie); // Some queue may be added when we unlock.
    CL_OBJECT_UNLOCK(event->ctx);

    if (q_list)
      cl_free(q_list);
  }

  return CL_SUCCESS;
}

LOCAL cl_int
cl_event_wait_for_event_ready(const cl_event event)
{
  assert(CL_OBJECT_IS_EVENT(event));
  return cl_event_wait_for_events_list(event->depend_event_num, event->depend_events);
}

LOCAL cl_int
cl_event_wait_for_events_list(cl_uint num_events, const cl_event *event_list)
{
  int i;
  cl_event e;
  cl_int ret = CL_SUCCESS;

  for (i = 0; i < num_events; i++) {
    e = event_list[i];
    assert(e);
    assert(CL_OBJECT_IS_EVENT(e));

    CL_OBJECT_LOCK(e);
    while (e->status > CL_COMPLETE) {
      CL_OBJECT_WAIT_ON_COND(e);
    }
    /* Iff some error happened, return the error. */
    if (e->status < CL_COMPLETE) {
      ret = CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST;
    }
    CL_OBJECT_UNLOCK(e);
  }

  return ret;
}

LOCAL cl_int
cl_event_check_waitlist(cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
                        cl_event *event, cl_context ctx)
{
  cl_int err = CL_SUCCESS;
  cl_int i;

  do {
    /* check the event_wait_list and num_events_in_wait_list */
    if ((event_wait_list == NULL) && (num_events_in_wait_list > 0)) {
      err = CL_INVALID_EVENT_WAIT_LIST;
      break;
    }

    if ((event_wait_list != NULL) && (num_events_in_wait_list == 0)) {
      err = CL_INVALID_EVENT_WAIT_LIST;
      break;
    }

    /* check the event and context */
    for (i = 0; i < num_events_in_wait_list; i++) {
      if (event_wait_list[i] == NULL || !CL_OBJECT_IS_EVENT(event_wait_list[i])) {
        err = CL_INVALID_EVENT;
        break;
      }

      if (cl_event_get_status(event_wait_list[i]) < CL_COMPLETE) {
        err = CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST;
        break;
      }

      if (event == event_wait_list + i) { /* Pointer of element of the wait list */
        err = CL_INVALID_EVENT_WAIT_LIST;
        break;
      }

      /* check all belong to same context. */
      if (ctx == NULL) {
        ctx = event_wait_list[i]->ctx;
      }
      if (event_wait_list[i]->ctx != ctx) {
        err = CL_INVALID_CONTEXT;
        break;
      }
    }

    if (err != CL_SUCCESS)
      break;

  } while (0);

  return err;
}

LOCAL void
cl_event_exec(cl_event event, cl_int exec_status)
{
  /* We are MT safe here, no one should call this
     at the same time. No need to lock */
  cl_int ret = CL_SUCCESS;
  cl_int status = cl_event_get_status(event);
  cl_int depend_status;

  if (status < CL_COMPLETE || status <= exec_status) {
    return;
  }

  depend_status = cl_event_is_ready(event);
  assert(depend_status <= CL_COMPLETE);
  if (depend_status < CL_COMPLETE) { // Error happend, cancel exec.
    ret = cl_event_set_status(event, depend_status);
    return;
  }

  /* Do the according thing based on event type. */
  ret = cl_enqueue_handle(&event->exec_data, exec_status);

  if (ret != CL_SUCCESS) {
    assert(ret < 0);
    DEBUGP(DL_WARNING, "Exec event %p error, type is %d, error staus is %d",
           event, event->event_type, ret);
    ret = cl_event_set_status(event, ret);
    assert(ret == CL_SUCCESS);
  } else {
    ret = cl_event_set_status(event, exec_status);
    assert(ret == CL_SUCCESS);
  }
}

/* 0 means ready, >0 means not ready, <0 means error. */
LOCAL cl_int
cl_event_is_ready(cl_event event)
{
  int i;
  int status;

  for (i = 0; i < event->depend_event_num; i++) {
    status = cl_event_get_status(event->depend_events[i]);

    if (status != CL_COMPLETE) {
      return status;
    }
  }

  return CL_COMPLETE;
}

LOCAL cl_event
cl_event_create_marker_or_barrier(cl_command_queue queue, cl_uint num_events_in_wait_list,
                                  const cl_event *event_wait_list, cl_bool is_barrier, cl_int *error)
{
  cl_event e = NULL;
  cl_int err = CL_SUCCESS;
  cl_command_type type = CL_COMMAND_MARKER;
  enqueue_type eq_type = EnqueueMarker;

  if (is_barrier) {
    type = CL_COMMAND_BARRIER;
    eq_type = EnqueueBarrier;
  }

  if (event_wait_list) {
    assert(num_events_in_wait_list > 0);

    e = cl_event_create(queue->ctx, queue, num_events_in_wait_list,
                        event_wait_list, type, &err);
    if (err != CL_SUCCESS) {
      *error = err;
      return NULL;
    }
  } else { /* The marker depends on all events in the queue now. */
    cl_command_queue_enqueue_worker worker = &queue->worker;
    cl_uint i;
    cl_uint event_num;
    cl_event *depend_events;

    CL_OBJECT_LOCK(queue);

    /* First, wait for the command queue retire all in executing event. */
    while (1) {
      if (worker->quit) { // already destroy the queue?
        CL_OBJECT_UNLOCK(queue);
        *error = CL_INVALID_COMMAND_QUEUE;
        return NULL;
      }

      if (worker->in_exec_status != CL_COMPLETE) {
        CL_OBJECT_WAIT_ON_COND(queue);
        continue;
      }

      break;
    }

    event_num = 0;
    depend_events = NULL;
    if (!list_empty(&worker->enqueued_events)) {
      depend_events = cl_command_queue_record_in_queue_events(queue, &event_num);
    }

    CL_OBJECT_UNLOCK(queue);

    e = cl_event_create(queue->ctx, queue, event_num, depend_events, type, &err);

    for (i = 0; i < event_num; i++) { //unref the temp
      cl_event_delete(depend_events[i]);
    }
    if (depend_events)
      cl_free(depend_events);

    if (err != CL_SUCCESS) {
      *error = err;
      return NULL;
    }
  }

  e->exec_data.type = eq_type;
  *error = CL_SUCCESS;
  return e;
}

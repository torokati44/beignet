/* 
 * Copyright © 2012 Intel Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Benjamin Segovia <benjamin.segovia@intel.com>
 */

#include "utest_helper.hpp"

static int *dst = NULL;
static const int w = 1024;
static const int h = 1024;

static void compiler_clod(void)
{
  const size_t global[2] = {size_t(w), size_t(h)};
  const size_t local[2] = {16, 1};
  const size_t sz = w * h * sizeof(char[4]);
  const float fx = float(w);
  const float fy = float(h);
  OCL_CREATE_KERNEL("compiler_clod");

  cl_mem cl_dst = clCreateBuffer(ctx, 0, sz, NULL, NULL);
  OCL_CALL (clSetKernelArg, kernel, 0, sizeof(cl_mem), &cl_dst);
  OCL_CALL (clSetKernelArg, kernel, 1, sizeof(float), &fx);
  OCL_CALL (clSetKernelArg, kernel, 2, sizeof(float), &fy);
  OCL_CALL (clSetKernelArg, kernel, 3, sizeof(int), &w);
  OCL_CALL (clEnqueueNDRangeKernel, queue, kernel, 2, NULL, global, local, 0, NULL, NULL);
  dst = (int *) clIntelMapBuffer(cl_dst, NULL);

  cl_write_bmp(dst, w, h, "clod.bmp");
  OCL_CALL (clIntelUnmapBuffer, cl_dst);
  OCL_CALL (clReleaseMemObject, cl_dst);
}

MAKE_UTEST_FROM_FUNCTION(compiler_clod);


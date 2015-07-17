DECL_SELECTION_IR(LABEL, LabelInstruction)
DECL_SELECTION_IR(MOV, UnaryInstruction)
DECL_SELECTION_IR(BSWAP, UnaryWithTempInstruction)
DECL_SELECTION_IR(MOV_DF, UnaryWithTempInstruction)
DECL_SELECTION_IR(LOAD_DF_IMM, UnaryWithTempInstruction)
DECL_SELECTION_IR(LOAD_INT64_IMM, UnaryInstruction)
DECL_SELECTION_IR(NOT, UnaryInstruction)
DECL_SELECTION_IR(LZD, UnaryInstruction)
DECL_SELECTION_IR(RNDZ, UnaryInstruction)
DECL_SELECTION_IR(RNDE, UnaryInstruction)
DECL_SELECTION_IR(RNDD, UnaryInstruction)
DECL_SELECTION_IR(RNDU, UnaryInstruction)
DECL_SELECTION_IR(FRC, UnaryInstruction)
DECL_SELECTION_IR(F16TO32, UnaryInstruction)
DECL_SELECTION_IR(F32TO16, UnaryInstruction)
DECL_SELECTION_IR(SEL, BinaryInstruction)
DECL_SELECTION_IR(SEL_INT64, BinaryInstruction)
DECL_SELECTION_IR(AND, BinaryInstruction)
DECL_SELECTION_IR(OR, BinaryInstruction)
DECL_SELECTION_IR(XOR, BinaryInstruction)
DECL_SELECTION_IR(I64AND, BinaryInstruction)
DECL_SELECTION_IR(I64OR, BinaryInstruction)
DECL_SELECTION_IR(I64XOR, BinaryInstruction)
DECL_SELECTION_IR(SHR, BinaryInstruction)
DECL_SELECTION_IR(SHL, BinaryInstruction)
DECL_SELECTION_IR(RSR, BinaryInstruction)
DECL_SELECTION_IR(RSL, BinaryInstruction)
DECL_SELECTION_IR(ASR, BinaryInstruction)
DECL_SELECTION_IR(SIMD_SHUFFLE, SimdShuffleInstruction)
DECL_SELECTION_IR(I64SHR, I64ShiftInstruction)
DECL_SELECTION_IR(I64SHL, I64ShiftInstruction)
DECL_SELECTION_IR(I64ASR, I64ShiftInstruction)
DECL_SELECTION_IR(ADD, BinaryInstruction)
DECL_SELECTION_IR(I64ADD, BinaryWithTempInstruction)
DECL_SELECTION_IR(I64SATADD, I64SATADDInstruction)
DECL_SELECTION_IR(I64SUB, BinaryWithTempInstruction)
DECL_SELECTION_IR(I64SATSUB, I64SATSUBInstruction)
DECL_SELECTION_IR(MUL, BinaryInstruction)
DECL_SELECTION_IR(I64MUL, I64MULInstruction)
DECL_SELECTION_IR(I64DIV, I64DIVREMInstruction)
DECL_SELECTION_IR(I64REM, I64DIVREMInstruction)
DECL_SELECTION_IR(ATOMIC, AtomicInstruction)
DECL_SELECTION_IR(MACH, BinaryInstruction)
DECL_SELECTION_IR(CMP, CompareInstruction)
DECL_SELECTION_IR(I64CMP, I64CompareInstruction)
DECL_SELECTION_IR(SEL_CMP, CompareInstruction)
DECL_SELECTION_IR(MAD, TernaryInstruction)
DECL_SELECTION_IR(JMPI, JumpInstruction)
DECL_SELECTION_IR(EOT, EotInstruction)
DECL_SELECTION_IR(INDIRECT_MOVE, IndirectMoveInstruction)
DECL_SELECTION_IR(NOP, NoOpInstruction)
DECL_SELECTION_IR(WAIT, WaitInstruction)
DECL_SELECTION_IR(MATH, MathInstruction)
DECL_SELECTION_IR(BARRIER, BarrierInstruction)
DECL_SELECTION_IR(FENCE, FenceInstruction)
DECL_SELECTION_IR(UNTYPED_READ, UntypedReadInstruction)
DECL_SELECTION_IR(UNTYPED_WRITE, UntypedWriteInstruction)
DECL_SELECTION_IR(READ64, Read64Instruction)
DECL_SELECTION_IR(WRITE64, Write64Instruction)
DECL_SELECTION_IR(BYTE_GATHER, ByteGatherInstruction)
DECL_SELECTION_IR(BYTE_SCATTER, ByteScatterInstruction)
DECL_SELECTION_IR(DWORD_GATHER, DWordGatherInstruction)
DECL_SELECTION_IR(PACK_BYTE, PackByteInstruction)
DECL_SELECTION_IR(UNPACK_BYTE, UnpackByteInstruction)
DECL_SELECTION_IR(PACK_LONG, PackLongInstruction)
DECL_SELECTION_IR(UNPACK_LONG, UnpackLongInstruction)
DECL_SELECTION_IR(SAMPLE, SampleInstruction)
DECL_SELECTION_IR(TYPED_WRITE, TypedWriteInstruction)
DECL_SELECTION_IR(SPILL_REG, SpillRegInstruction)
DECL_SELECTION_IR(UNSPILL_REG, UnSpillRegInstruction)
DECL_SELECTION_IR(MUL_HI, BinaryWithTempInstruction)
DECL_SELECTION_IR(I64_MUL_HI, I64MULHIInstruction)
DECL_SELECTION_IR(FBH, UnaryInstruction)
DECL_SELECTION_IR(FBL, UnaryInstruction)
DECL_SELECTION_IR(CBIT, UnaryInstruction)
DECL_SELECTION_IR(HADD, BinaryWithTempInstruction)
DECL_SELECTION_IR(RHADD, BinaryWithTempInstruction)
DECL_SELECTION_IR(I64HADD, I64HADDInstruction)
DECL_SELECTION_IR(I64RHADD, I64RHADDInstruction)
DECL_SELECTION_IR(UPSAMPLE_LONG, BinaryInstruction)
DECL_SELECTION_IR(CONVI_TO_I64, UnaryWithTempInstruction)
DECL_SELECTION_IR(CONVI64_TO_I, UnaryInstruction)
DECL_SELECTION_IR(CONVI64_TO_F, I64ToFloatInstruction)
DECL_SELECTION_IR(CONVF_TO_I64, FloatToI64Instruction)
DECL_SELECTION_IR(I64MADSAT, I64MADSATInstruction)
DECL_SELECTION_IR(BRC, UnaryInstruction)
DECL_SELECTION_IR(BRD, UnaryInstruction)
DECL_SELECTION_IR(IF, UnaryInstruction)
DECL_SELECTION_IR(ENDIF, UnaryInstruction)
DECL_SELECTION_IR(ELSE, UnaryInstruction)
DECL_SELECTION_IR(READ_ARF, UnaryInstruction)
DECL_SELECTION_IR(WHILE, UnaryInstruction)

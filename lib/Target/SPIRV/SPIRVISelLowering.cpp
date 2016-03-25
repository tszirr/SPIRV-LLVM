//===-- SPIRVISelLowering.cpp - SPIRV DAG Lowering Implementation ---------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
// Copyright (c) 2014 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal with the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimers.
// Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimers in the documentation
// and/or other materials provided with the distribution.
// Neither the names of Advanced Micro Devices, Inc., nor the names of its
// contributors may be used to endorse or promote products derived from this
// Software without specific prior written permission.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH
// THE SOFTWARE.
//===----------------------------------------------------------------------===//
//
// This file defines the interfaces that SPIRV uses to lower LLVM code into a
// selection DAG.
//
//===----------------------------------------------------------------------===//

#include "SPIRVTargetMachine.h"

#include "SPIRVGenInstrInfo.inc"

#define DEBUG_TYPE "spirv-isel"

using namespace llvm;

SPIRVTargetLowering::SPIRVTargetLowering(SPIRVTargetMachine &TM)
   : TargetLowering(TM)
{
  addRegisterClass(MVT::i32, &SPIRV::GPR32RegClass);
  addRegisterClass(MVT::i64, &SPIRV::GPR64RegClass);
  addRegisterClass(MVT::f16, &SPIRV::GPR16RegClass);
  addRegisterClass(MVT::f32, &SPIRV::GPR32RegClass);
  addRegisterClass(MVT::f64, &SPIRV::GPR64RegClass);
  addRegisterClass(MVT::i1,  &SPIRV::GPR1RegClass);

  computeRegisterProperties();
}

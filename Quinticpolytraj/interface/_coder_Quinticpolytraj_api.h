//
// File: _coder_Quinticpolytraj_api.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Dec-2023 23:22:41
//

#ifndef _CODER_QUINTICPOLYTRAJ_API_H
#define _CODER_QUINTICPOLYTRAJ_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Type Definitions
struct struct0_T {
  coder::array<real_T, 2U> breaks;
  coder::array<real_T, 3U> coefs;
};

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void Quinticpolytraj(coder::array<real_T, 2U> *wpts,
                     coder::array<real_T, 2U> *tpts,
                     coder::array<real_T, 2U> *tvec,
                     coder::array<real_T, 2U> *e, coder::array<real_T, 2U> *q,
                     coder::array<real_T, 2U> *qd,
                     coder::array<real_T, 2U> *qdd, struct0_T *pp);

void QuinticpolytrajNolimit(coder::array<real_T, 2U> *wpts,
                            coder::array<real_T, 2U> *tpts,
                            coder::array<real_T, 2U> *tvec,
                            coder::array<real_T, 2U> *q,
                            coder::array<real_T, 2U> *qd,
                            coder::array<real_T, 2U> *qdd, struct0_T *pp);

void QuinticpolytrajNolimit_api(const mxArray *const prhs[3], int32_T nlhs,
                                const mxArray *plhs[4]);

void Quinticpolytraj_api(const mxArray *const prhs[4], int32_T nlhs,
                         const mxArray *plhs[4]);

void Quinticpolytraj_atexit();

void Quinticpolytraj_initialize();

void Quinticpolytraj_terminate();

void Quinticpolytraj_xil_shutdown();

void Quinticpolytraj_xil_terminate();

#endif
//
// File trailer for _coder_Quinticpolytraj_api.h
//
// [EOF]
//

//
// File: _coder_Quinticpolytraj_mex.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Dec-2023 23:22:41
//

#ifndef _CODER_QUINTICPOLYTRAJ_MEX_H
#define _CODER_QUINTICPOLYTRAJ_MEX_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void unsafe_QuinticpolytrajNolimit_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                               int32_T nrhs,
                                               const mxArray *prhs[3]);

void unsafe_Quinticpolytraj_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                        int32_T nrhs, const mxArray *prhs[4]);

#endif
//
// File trailer for _coder_Quinticpolytraj_mex.h
//
// [EOF]
//

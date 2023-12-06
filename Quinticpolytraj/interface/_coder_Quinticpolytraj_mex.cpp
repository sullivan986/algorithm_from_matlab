//
// File: _coder_Quinticpolytraj_mex.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Dec-2023 23:22:41
//

// Include Files
#include "_coder_Quinticpolytraj_mex.h"
#include "_coder_Quinticpolytraj_api.h"

// Function Definitions
//
// Arguments    : int32_T nlhs
//                mxArray *plhs[]
//                int32_T nrhs
//                const mxArray *prhs[]
// Return Type  : void
//
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  static const char_T *emlrtEntryPoints[2]{"Quinticpolytraj",
                                           "QuinticpolytrajNolimit"};
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexAtExit(&Quinticpolytraj_atexit);
  // Module initialization.
  Quinticpolytraj_initialize();
  st.tls = emlrtRootTLSGlobal;
  // Dispatch the entry-point.
  switch (emlrtGetEntryPointIndexR2016a(
      &st, nrhs, &prhs[0], (const char_T **)&emlrtEntryPoints[0], 2)) {
  case 0:
    unsafe_Quinticpolytraj_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 1:
    unsafe_QuinticpolytrajNolimit_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  }
  // Module termination.
  Quinticpolytraj_terminate();
}

//
// Arguments    : void
// Return Type  : emlrtCTX
//
emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           nullptr, "GBK", true);
  return emlrtRootTLSGlobal;
}

//
// Arguments    : int32_T nlhs
//                mxArray *plhs[4]
//                int32_T nrhs
//                const mxArray *prhs[3]
// Return Type  : void
//
void unsafe_QuinticpolytrajNolimit_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                               int32_T nrhs,
                                               const mxArray *prhs[3])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[4];
  const mxArray *b_prhs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        22, "QuinticpolytrajNolimit");
  }
  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 22,
                        "QuinticpolytrajNolimit");
  }
  // Call the function.
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  b_prhs[2] = prhs[2];
  QuinticpolytrajNolimit_api(b_prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

//
// Arguments    : int32_T nlhs
//                mxArray *plhs[4]
//                int32_T nrhs
//                const mxArray *prhs[4]
// Return Type  : void
//
void unsafe_Quinticpolytraj_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                        int32_T nrhs, const mxArray *prhs[4])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *b_prhs[4];
  const mxArray *outputs[4];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        15, "Quinticpolytraj");
  }
  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 15,
                        "Quinticpolytraj");
  }
  // Call the function.
  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  b_prhs[2] = prhs[2];
  b_prhs[3] = prhs[3];
  Quinticpolytraj_api(b_prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

//
// File trailer for _coder_Quinticpolytraj_mex.cpp
//
// [EOF]
//

//
// File: _coder_Quinticpolytraj_api.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Dec-2023 23:22:41
//

// Include Files
#include "_coder_Quinticpolytraj_api.h"
#include "_coder_Quinticpolytraj_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131643U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "Quinticpolytraj",                                    // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier,
                               coder::array<real_T, 2U> &y);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y);

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static const mxArray *emlrt_marshallOut(const struct0_T &u);

// Function Definitions
//
// Arguments    : const emlrtStack &sp
//                const mxArray *b_nullptr
//                const char_T *identifier
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier,
                               coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y)
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 2U> &ret
// Return Type  : void
//
static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{3, -1};
  int32_T iv[2];
  boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(iv[0], iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 2U> &ret
// Return Type  : void
//
static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{1, -1};
  int32_T iv[2];
  boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(iv[0], iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *b_nullptr
//                const char_T *identifier
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const coder::array<real_T, 2U> &u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  static const int32_T iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const struct0_T &u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const struct0_T &u)
{
  static const char_T *sv[2]{"breaks", "coefs"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv1[3];
  int32_T iv[2];
  int32_T i;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv[0]));
  b_y = nullptr;
  iv[0] = 1;
  iv[1] = u.breaks.size(1);
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < u.breaks.size(1); b_i++) {
    pData[i] = u.breaks[b_i];
    i++;
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "breaks", b_y, 0);
  c_y = nullptr;
  iv1[0] = 3;
  iv1[1] = u.coefs.size(1);
  iv1[2] = 6;
  m = emlrtCreateNumericArray(3, &iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < 6; b_i++) {
    for (int32_T c_i{0}; c_i < u.coefs.size(1); c_i++) {
      pData[i] = u.coefs[3 * c_i + 3 * u.coefs.size(1) * b_i];
      pData[i + 1] = u.coefs[(3 * c_i + 3 * u.coefs.size(1) * b_i) + 1];
      pData[i + 2] = u.coefs[(3 * c_i + 3 * u.coefs.size(1) * b_i) + 2];
      i += 3;
    }
  }
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "coefs", c_y, 1);
  return y;
}

//
// Arguments    : const mxArray * const prhs[3]
//                int32_T nlhs
//                const mxArray *plhs[4]
// Return Type  : void
//
void QuinticpolytrajNolimit_api(const mxArray *const prhs[3], int32_T nlhs,
                                const mxArray *plhs[4])
{
  coder::array<real_T, 2U> q;
  coder::array<real_T, 2U> qd;
  coder::array<real_T, 2U> qdd;
  coder::array<real_T, 2U> tpts;
  coder::array<real_T, 2U> tvec;
  coder::array<real_T, 2U> wpts;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct0_T pp;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  wpts.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[0]), "wpts", wpts);
  tpts.no_free();
  b_emlrt_marshallIn(st, emlrtAlias(prhs[1]), "tpts", tpts);
  tvec.no_free();
  b_emlrt_marshallIn(st, emlrtAlias(prhs[2]), "tvec", tvec);
  // Invoke the target function
  QuinticpolytrajNolimit(wpts, tpts, tvec, q, qd, qdd, &pp);
  // Marshall function outputs
  q.no_free();
  plhs[0] = emlrt_marshallOut(q);
  if (nlhs > 1) {
    qd.no_free();
    plhs[1] = emlrt_marshallOut(qd);
  }
  if (nlhs > 2) {
    qdd.no_free();
    plhs[2] = emlrt_marshallOut(qdd);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(pp);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray * const prhs[4]
//                int32_T nlhs
//                const mxArray *plhs[4]
// Return Type  : void
//
void Quinticpolytraj_api(const mxArray *const prhs[4], int32_T nlhs,
                         const mxArray *plhs[4])
{
  coder::array<real_T, 2U> e;
  coder::array<real_T, 2U> q;
  coder::array<real_T, 2U> qd;
  coder::array<real_T, 2U> qdd;
  coder::array<real_T, 2U> tpts;
  coder::array<real_T, 2U> tvec;
  coder::array<real_T, 2U> wpts;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct0_T pp;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  wpts.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[0]), "wpts", wpts);
  tpts.no_free();
  b_emlrt_marshallIn(st, emlrtAlias(prhs[1]), "tpts", tpts);
  tvec.no_free();
  b_emlrt_marshallIn(st, emlrtAlias(prhs[2]), "tvec", tvec);
  e.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[3]), "e", e);
  // Invoke the target function
  Quinticpolytraj(wpts, tpts, tvec, e, q, qd, qdd, &pp);
  // Marshall function outputs
  q.no_free();
  plhs[0] = emlrt_marshallOut(q);
  if (nlhs > 1) {
    qd.no_free();
    plhs[1] = emlrt_marshallOut(qd);
  }
  if (nlhs > 2) {
    qdd.no_free();
    plhs[2] = emlrt_marshallOut(qdd);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(pp);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : void
// Return Type  : void
//
void Quinticpolytraj_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  Quinticpolytraj_xil_terminate();
  Quinticpolytraj_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void Quinticpolytraj_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void Quinticpolytraj_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// File trailer for _coder_Quinticpolytraj_api.cpp
//
// [EOF]
//

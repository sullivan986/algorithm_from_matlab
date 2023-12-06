//
// File: Quinticpolytraj.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Dec-2023 23:22:41
//

// Include Files
#include "Quinticpolytraj.h"
#include "Quinticpolytraj_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Declarations
namespace coder {
static void ppval(const array<double, 2U> &pp_breaks,
                  const array<double, 3U> &pp_coefs, const array<double, 2U> &x,
                  array<double, 2U> &v);

namespace robotics {
namespace core {
namespace internal {
static void addFlatSegmentsToPPFormParts(const array<double, 2U> &oldbreaks,
                                         const array<double, 2U> &oldCoeffs,
                                         array<double, 2U> &newBreaks,
                                         array<double, 2U> &newCoefs);

static void changeEndSegBreaks(array<double, 2U> &oldBreaks,
                               const array<double, 2U> &evalTime);

} // namespace internal
} // namespace core
} // namespace robotics
} // namespace coder
static double rt_powd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : const array<double, 2U> &pp_breaks
//                const array<double, 3U> &pp_coefs
//                const array<double, 2U> &x
//                array<double, 2U> &v
// Return Type  : void
//
namespace coder {
static void ppval(const array<double, 2U> &pp_breaks,
                  const array<double, 3U> &pp_coefs, const array<double, 2U> &x,
                  array<double, 2U> &v)
{
  int coefStride;
  int nx;
  coefStride = 3 * (pp_breaks.size(1) - 1);
  v.set_size(3, x.size(1));
  nx = x.size(1);
  for (int ix{0}; ix < nx; ix++) {
    int iv0;
    iv0 = ix * 3;
    if (std::isnan(x[ix])) {
      v[iv0] = x[ix];
      v[iv0 + 1] = x[ix];
      v[iv0 + 2] = x[ix];
    } else {
      double xloc;
      int high_i;
      int low_i;
      int low_ip1;
      int mid_i;
      high_i = pp_breaks.size(1);
      low_i = 1;
      low_ip1 = 2;
      while (high_i > low_ip1) {
        mid_i = (low_i >> 1) + (high_i >> 1);
        if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
          mid_i++;
        }
        if (x[ix] >= pp_breaks[mid_i - 1]) {
          low_i = mid_i;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }
      low_ip1 = (low_i - 1) * 3;
      xloc = x[ix] - pp_breaks[low_i - 1];
      v[iv0] = pp_coefs[low_ip1];
      v[iv0 + 1] = pp_coefs[low_ip1 + 1];
      v[iv0 + 2] = pp_coefs[low_ip1 + 2];
      for (mid_i = 0; mid_i < 5; mid_i++) {
        high_i = low_ip1 + (mid_i + 1) * coefStride;
        v[iv0] = xloc * v[iv0] + pp_coefs[high_i];
        v[iv0 + 1] = xloc * v[iv0 + 1] + pp_coefs[high_i + 1];
        v[iv0 + 2] = xloc * v[iv0 + 2] + pp_coefs[high_i + 2];
      }
    }
  }
}

//
// Arguments    : const array<double, 2U> &oldbreaks
//                const array<double, 2U> &oldCoeffs
//                array<double, 2U> &newBreaks
//                array<double, 2U> &newCoefs
// Return Type  : void
//
namespace robotics {
namespace core {
namespace internal {
static void addFlatSegmentsToPPFormParts(const array<double, 2U> &oldbreaks,
                                         const array<double, 2U> &oldCoeffs,
                                         array<double, 2U> &newBreaks,
                                         array<double, 2U> &newCoefs)
{
  static const signed char iv[6]{0, 0, 0, 0, 0, 1};
  array<double, 2U> breaksWithFlatStart;
  array<double, 2U> coefsWithFlatStart;
  array<double, 1U> valueAtEnd;
  double newSegmentCoeffs[18];
  double evalPointVector[6];
  double holdPoint;
  double holdPoint_tmp;
  int i;
  int i1;
  int loop_ub;
  std::memset(&newSegmentCoeffs[0], 0, 18U * sizeof(double));
  for (i = 0; i < 3; i++) {
    holdPoint = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      holdPoint +=
          oldCoeffs[i + oldCoeffs.size(0) * i1] * static_cast<double>(iv[i1]);
    }
    newSegmentCoeffs[i + 15] = holdPoint;
  }
  coefsWithFlatStart.set_size(oldCoeffs.size(0) + 3, 6);
  loop_ub = (oldCoeffs.size(0) + 3) * 6;
  for (i = 0; i < loop_ub; i++) {
    coefsWithFlatStart[i] = 0.0;
  }
  for (i = 0; i < 6; i++) {
    coefsWithFlatStart[coefsWithFlatStart.size(0) * i] =
        newSegmentCoeffs[3 * i];
    coefsWithFlatStart[coefsWithFlatStart.size(0) * i + 1] =
        newSegmentCoeffs[3 * i + 1];
    coefsWithFlatStart[coefsWithFlatStart.size(0) * i + 2] =
        newSegmentCoeffs[3 * i + 2];
  }
  if (static_cast<unsigned int>(oldCoeffs.size(0)) + 3U < 4U) {
    i = 0;
  } else {
    i = 3;
  }
  loop_ub = oldCoeffs.size(0);
  for (i1 = 0; i1 < 6; i1++) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      coefsWithFlatStart[(i + b_i) + coefsWithFlatStart.size(0) * i1] =
          oldCoeffs[b_i + oldCoeffs.size(0) * i1];
    }
  }
  breaksWithFlatStart.set_size(1, oldbreaks.size(1) + 1);
  breaksWithFlatStart[0] = oldbreaks[0] - 1.0;
  loop_ub = oldbreaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    breaksWithFlatStart[i + 1] = oldbreaks[i];
  }
  holdPoint_tmp = breaksWithFlatStart[breaksWithFlatStart.size(1) - 1];
  holdPoint =
      holdPoint_tmp - breaksWithFlatStart[breaksWithFlatStart.size(1) - 2];
  for (int b_i{0}; b_i < 6; b_i++) {
    evalPointVector[b_i] =
        rt_powd_snf(holdPoint, 6.0 - (static_cast<double>(b_i) + 1.0));
  }
  if (coefsWithFlatStart.size(0) - 2 > coefsWithFlatStart.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    i = coefsWithFlatStart.size(0) - 3;
    i1 = coefsWithFlatStart.size(0);
  }
  loop_ub = i1 - i;
  valueAtEnd.set_size(loop_ub);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    holdPoint = 0.0;
    for (int k{0}; k < 6; k++) {
      i1 = k * loop_ub + b_i;
      holdPoint +=
          coefsWithFlatStart[(i + i1 % loop_ub) +
                             coefsWithFlatStart.size(0) * (i1 / loop_ub)] *
          evalPointVector[k];
    }
    valueAtEnd[b_i] = holdPoint;
  }
  std::memset(&newSegmentCoeffs[0], 0, 18U * sizeof(double));
  newSegmentCoeffs[15] = valueAtEnd[0];
  newSegmentCoeffs[16] = valueAtEnd[1];
  newSegmentCoeffs[17] = valueAtEnd[2];
  newCoefs.set_size(coefsWithFlatStart.size(0) + 3, 6);
  loop_ub = (coefsWithFlatStart.size(0) + 3) * 6;
  for (i = 0; i < loop_ub; i++) {
    newCoefs[i] = 0.0;
  }
  loop_ub = coefsWithFlatStart.size(0);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      newCoefs[i1 + newCoefs.size(0) * i] =
          coefsWithFlatStart[i1 + coefsWithFlatStart.size(0) * i];
    }
  }
  for (i = 0; i < 6; i++) {
    newCoefs[coefsWithFlatStart.size(0) + newCoefs.size(0) * i] =
        newSegmentCoeffs[3 * i];
    newCoefs[(coefsWithFlatStart.size(0) + newCoefs.size(0) * i) + 1] =
        newSegmentCoeffs[3 * i + 1];
    newCoefs[(coefsWithFlatStart.size(0) + newCoefs.size(0) * i) + 2] =
        newSegmentCoeffs[3 * i + 2];
  }
  newBreaks.set_size(1, breaksWithFlatStart.size(1) + 1);
  loop_ub = breaksWithFlatStart.size(1);
  for (i = 0; i < loop_ub; i++) {
    newBreaks[i] = breaksWithFlatStart[i];
  }
  newBreaks[breaksWithFlatStart.size(1)] = holdPoint_tmp + 1.0;
}

//
// Arguments    : array<double, 2U> &oldBreaks
//                const array<double, 2U> &evalTime
// Return Type  : void
//
static void changeEndSegBreaks(array<double, 2U> &oldBreaks,
                               const array<double, 2U> &evalTime)
{
  array<bool, 2U> x;
  double dt;
  double oldBreaks_tmp;
  int idx;
  int ii;
  int ii_data;
  int loop_ub;
  unsigned int tGreaterThanTfIdx_data;
  bool exitg1;
  dt = 0.01;
  x.set_size(1, evalTime.size(1));
  oldBreaks_tmp = oldBreaks[oldBreaks.size(1) - 2];
  loop_ub = evalTime.size(1);
  for (idx = 0; idx < loop_ub; idx++) {
    x[idx] = (evalTime[idx] > oldBreaks_tmp);
  }
  loop_ub = (x.size(1) >= 1);
  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x.size(1) - 1)) {
    if (x[ii]) {
      idx = 1;
      ii_data = ii + 1;
      exitg1 = true;
    } else {
      ii++;
    }
  }
  if (loop_ub == 1) {
    if (idx == 0) {
      loop_ub = 0;
    }
  } else {
    loop_ub = (idx >= 1);
  }
  if (loop_ub - 1 >= 0) {
    tGreaterThanTfIdx_data = static_cast<unsigned int>(ii_data);
  }
  if (loop_ub != 0) {
    dt = std::fmin((evalTime[static_cast<int>(tGreaterThanTfIdx_data) - 1] -
                    oldBreaks_tmp) /
                       2.0,
                   0.01);
  }
  oldBreaks[oldBreaks.size(1) - 2] = oldBreaks_tmp + dt;
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
} // namespace internal
} // namespace core
} // namespace robotics
} // namespace coder
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = std::abs(u0);
    d1 = std::abs(u1);
    if (std::isinf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = std::pow(u0, u1);
    }
  }
  return y;
}

//
// Arguments    : const coder::array<double, 2U> &wpts
//                const coder::array<double, 2U> &tpts
//                const coder::array<double, 2U> &tvec
//                const coder::array<double, 2U> &e
//                coder::array<double, 2U> &q
//                coder::array<double, 2U> &qd
//                coder::array<double, 2U> &qdd
//                struct0_T *pp
// Return Type  : void
//
void Quinticpolytraj(const coder::array<double, 2U> &wpts,
                     const coder::array<double, 2U> &tpts,
                     const coder::array<double, 2U> &tvec,
                     const coder::array<double, 2U> &e,
                     coder::array<double, 2U> &q, coder::array<double, 2U> &qd,
                     coder::array<double, 2U> &qdd, struct0_T *pp)
{
  coder::array<double, 3U> ppd_coefs;
  coder::array<double, 2U> b_tpts;
  coder::array<double, 2U> coefMat;
  coder::array<double, 2U> dCoeffs;
  coder::array<double, 2U> derivativeBreaks;
  coder::array<double, 2U> modCoeffs;
  coder::array<double, 2U> r;
  int i;
  int loop_ub;
  int loop_ub_tmp;
  q.set_size(3, tvec.size(1));
  loop_ub_tmp = 3 * tvec.size(1);
  qd.set_size(3, tvec.size(1));
  qdd.set_size(3, tvec.size(1));
  for (i = 0; i < loop_ub_tmp; i++) {
    q[i] = 0.0;
    qd[i] = 0.0;
    qdd[i] = 0.0;
  }
  i = (wpts.size(1) - 1) * 3;
  coefMat.set_size(i, 6);
  loop_ub = i * 6;
  for (i = 0; i < loop_ub; i++) {
    coefMat[i] = 0.0;
  }
  i = wpts.size(1);
  for (int b_i{0}; b_i <= i - 2; b_i++) {
    double d;
    double d1;
    double d2;
    double d3;
    double finalTime;
    finalTime = tpts[b_i + 1] - tpts[b_i];
    d = rt_powd_snf(finalTime, 3.0);
    d1 = rt_powd_snf(finalTime, 4.0);
    d2 = rt_powd_snf(finalTime, 5.0);
    d3 = finalTime * finalTime;
    for (loop_ub_tmp = 0; loop_ub_tmp < 3; loop_ub_tmp++) {
      double dv[9];
      double coeffVec[6];
      double y[3];
      double wpts_idx_1;
      double wpts_idx_2;
      double xtmp;
      int c_i;
      coeffVec[0] = wpts[loop_ub_tmp + 3 * b_i];
      coeffVec[1] = e[loop_ub_tmp + 3 * b_i];
      coeffVec[3] = 0.0;
      coeffVec[4] = 0.0;
      coeffVec[5] = 0.0;
      dv[0] = 1.0;
      dv[3] = finalTime;
      dv[6] = d3;
      dv[1] = 0.0;
      dv[4] = 1.0;
      dv[7] = 2.0 * finalTime;
      dv[2] = 0.0;
      dv[5] = 0.0;
      dv[8] = 2.0;
      xtmp = coeffVec[0];
      wpts_idx_1 = coeffVec[1];
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        y[loop_ub] = (dv[loop_ub] * xtmp + dv[loop_ub + 3] * wpts_idx_1) +
                     dv[loop_ub + 6] * 0.0;
      }
      dv[0] = 10.0 / d;
      dv[3] = -4.0 / d3;
      dv[6] = 1.0 / (2.0 * finalTime);
      dv[1] = -15.0 / d1;
      dv[4] = 7.0 / d;
      dv[7] = -1.0 / d3;
      dv[2] = 6.0 / d2;
      dv[5] = -3.0 / d1;
      dv[8] = 1.0 / (2.0 * d);
      xtmp =
          wpts[loop_ub_tmp +
               3 * (static_cast<int>((static_cast<double>(b_i) + 1.0) + 1.0) -
                    1)] -
          y[0];
      wpts_idx_1 =
          e[loop_ub_tmp +
            3 * (static_cast<int>((static_cast<double>(b_i) + 1.0) + 1.0) -
                 1)] -
          y[1];
      wpts_idx_2 = 0.0 - y[2];
      for (c_i = 0; c_i < 3; c_i++) {
        coeffVec[c_i + 3] = (dv[c_i] * xtmp + dv[c_i + 3] * wpts_idx_1) +
                            dv[c_i + 6] * wpts_idx_2;
      }
      xtmp = coeffVec[0];
      coeffVec[0] = coeffVec[5];
      coeffVec[5] = xtmp;
      xtmp = coeffVec[1];
      coeffVec[1] = coeffVec[4];
      coeffVec[4] = xtmp;
      coeffVec[2] = coeffVec[3];
      coeffVec[3] = 0.0;
      c_i = static_cast<int>(((static_cast<double>(b_i) + 1.0) - 1.0) * 3.0 +
                             (static_cast<double>(loop_ub_tmp) + 1.0));
      for (loop_ub = 0; loop_ub < 6; loop_ub++) {
        coefMat[(c_i + coefMat.size(0) * loop_ub) - 1] = coeffVec[loop_ub];
      }
    }
  }
  b_tpts.set_size(1, tpts.size(1));
  loop_ub = tpts.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_tpts[i] = tpts[i];
  }
  coder::robotics::core::internal::addFlatSegmentsToPPFormParts(
      b_tpts, coefMat, derivativeBreaks, modCoeffs);
  pp->coefs.set_size(3, derivativeBreaks.size(1) - 1, 6);
  loop_ub = 3 * (derivativeBreaks.size(1) - 1) * 6;
  for (i = 0; i < loop_ub; i++) {
    pp->coefs[i] = modCoeffs[i];
  }
  pp->breaks.set_size(1, derivativeBreaks.size(1));
  loop_ub = derivativeBreaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    pp->breaks[i] = derivativeBreaks[i];
  }
  coder::ppval(pp->breaks, pp->coefs, tvec, r);
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    q[3 * i] = r[3 * i];
    q[3 * i + 1] = r[3 * i + 1];
    q[3 * i + 2] = r[3 * i + 2];
  }
  coder::robotics::core::internal::changeEndSegBreaks(derivativeBreaks, tvec);
  dCoeffs.set_size(modCoeffs.size(0), 6);
  loop_ub = modCoeffs.size(0) * 6;
  for (i = 0; i < loop_ub; i++) {
    dCoeffs[i] = 0.0;
  }
  loop_ub = modCoeffs.size(0);
  for (int b_i{0}; b_i < 5; b_i++) {
    for (i = 0; i < loop_ub; i++) {
      dCoeffs[i + dCoeffs.size(0) * (b_i + 1)] =
          ((6.0 - (static_cast<double>(b_i) + 2.0)) + 1.0) *
          modCoeffs[i + modCoeffs.size(0) * b_i];
    }
  }
  ppd_coefs.set_size(3, derivativeBreaks.size(1) - 1, 6);
  loop_ub_tmp = 3 * (derivativeBreaks.size(1) - 1) * 6;
  for (i = 0; i < loop_ub_tmp; i++) {
    ppd_coefs[i] = dCoeffs[i];
  }
  b_tpts.set_size(1, derivativeBreaks.size(1));
  loop_ub = derivativeBreaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_tpts[i] = derivativeBreaks[i];
  }
  coder::ppval(b_tpts, ppd_coefs, tvec, r);
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    qd[3 * i] = r[3 * i];
    qd[3 * i + 1] = r[3 * i + 1];
    qd[3 * i + 2] = r[3 * i + 2];
  }
  coefMat.set_size(dCoeffs.size(0), 6);
  loop_ub = dCoeffs.size(0) * 6;
  for (i = 0; i < loop_ub; i++) {
    coefMat[i] = 0.0;
  }
  loop_ub = dCoeffs.size(0);
  for (int b_i{0}; b_i < 5; b_i++) {
    for (i = 0; i < loop_ub; i++) {
      coefMat[i + coefMat.size(0) * (b_i + 1)] =
          ((6.0 - (static_cast<double>(b_i) + 2.0)) + 1.0) *
          dCoeffs[i + dCoeffs.size(0) * b_i];
    }
  }
  ppd_coefs.set_size(3, derivativeBreaks.size(1) - 1, 6);
  for (i = 0; i < loop_ub_tmp; i++) {
    ppd_coefs[i] = coefMat[i];
  }
  b_tpts.set_size(1, derivativeBreaks.size(1));
  loop_ub = derivativeBreaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_tpts[i] = derivativeBreaks[i];
  }
  coder::ppval(b_tpts, ppd_coefs, tvec, r);
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    qdd[3 * i] = r[3 * i];
    qdd[3 * i + 1] = r[3 * i + 1];
    qdd[3 * i + 2] = r[3 * i + 2];
  }
}

//
// Arguments    : const coder::array<double, 2U> &wpts
//                const coder::array<double, 2U> &tpts
//                const coder::array<double, 2U> &tvec
//                coder::array<double, 2U> &q
//                coder::array<double, 2U> &qd
//                coder::array<double, 2U> &qdd
//                struct0_T *pp
// Return Type  : void
//
void QuinticpolytrajNolimit(const coder::array<double, 2U> &wpts,
                            const coder::array<double, 2U> &tpts,
                            const coder::array<double, 2U> &tvec,
                            coder::array<double, 2U> &q,
                            coder::array<double, 2U> &qd,
                            coder::array<double, 2U> &qdd, struct0_T *pp)
{
  coder::array<double, 3U> ppd_coefs;
  coder::array<double, 2U> b_tpts;
  coder::array<double, 2U> coefMat;
  coder::array<double, 2U> dCoeffs;
  coder::array<double, 2U> derivativeBreaks;
  coder::array<double, 2U> modCoeffs;
  coder::array<double, 2U> r;
  int i;
  int loop_ub;
  int loop_ub_tmp;
  q.set_size(3, tvec.size(1));
  loop_ub_tmp = 3 * tvec.size(1);
  qd.set_size(3, tvec.size(1));
  qdd.set_size(3, tvec.size(1));
  for (i = 0; i < loop_ub_tmp; i++) {
    q[i] = 0.0;
    qd[i] = 0.0;
    qdd[i] = 0.0;
  }
  i = (wpts.size(1) - 1) * 3;
  coefMat.set_size(i, 6);
  loop_ub = i * 6;
  for (i = 0; i < loop_ub; i++) {
    coefMat[i] = 0.0;
  }
  i = wpts.size(1);
  for (int b_i{0}; b_i <= i - 2; b_i++) {
    double d;
    double d1;
    double d2;
    double d3;
    double finalTime;
    finalTime = tpts[b_i + 1] - tpts[b_i];
    d = rt_powd_snf(finalTime, 3.0);
    d1 = rt_powd_snf(finalTime, 4.0);
    d2 = rt_powd_snf(finalTime, 5.0);
    d3 = finalTime * finalTime;
    for (loop_ub_tmp = 0; loop_ub_tmp < 3; loop_ub_tmp++) {
      double dv[9];
      double coeffVec[6];
      double y[3];
      double wpts_idx_1;
      double wpts_idx_2;
      double xtmp;
      int c_i;
      coeffVec[0] = wpts[loop_ub_tmp + 3 * b_i];
      coeffVec[3] = 0.0;
      coeffVec[4] = 0.0;
      coeffVec[5] = 0.0;
      dv[0] = 1.0;
      dv[3] = finalTime;
      dv[6] = d3;
      dv[1] = 0.0;
      dv[4] = 1.0;
      dv[7] = 2.0 * finalTime;
      dv[2] = 0.0;
      dv[5] = 0.0;
      dv[8] = 2.0;
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        y[loop_ub] = (dv[loop_ub] * coeffVec[0] + dv[loop_ub + 3] * 0.0) +
                     dv[loop_ub + 6] * 0.0;
      }
      dv[0] = 10.0 / d;
      dv[3] = -4.0 / d3;
      dv[6] = 1.0 / (2.0 * finalTime);
      dv[1] = -15.0 / d1;
      dv[4] = 7.0 / d;
      dv[7] = -1.0 / d3;
      dv[2] = 6.0 / d2;
      dv[5] = -3.0 / d1;
      dv[8] = 1.0 / (2.0 * d);
      xtmp =
          wpts[loop_ub_tmp +
               3 * (static_cast<int>((static_cast<double>(b_i) + 1.0) + 1.0) -
                    1)] -
          y[0];
      wpts_idx_1 = 0.0 - y[1];
      wpts_idx_2 = 0.0 - y[2];
      for (c_i = 0; c_i < 3; c_i++) {
        coeffVec[c_i + 3] = (dv[c_i] * xtmp + dv[c_i + 3] * wpts_idx_1) +
                            dv[c_i + 6] * wpts_idx_2;
      }
      xtmp = coeffVec[0];
      coeffVec[0] = coeffVec[5];
      coeffVec[5] = xtmp;
      coeffVec[1] = coeffVec[4];
      coeffVec[4] = 0.0;
      coeffVec[2] = coeffVec[3];
      coeffVec[3] = 0.0;
      c_i = static_cast<int>(((static_cast<double>(b_i) + 1.0) - 1.0) * 3.0 +
                             (static_cast<double>(loop_ub_tmp) + 1.0));
      for (loop_ub = 0; loop_ub < 6; loop_ub++) {
        coefMat[(c_i + coefMat.size(0) * loop_ub) - 1] = coeffVec[loop_ub];
      }
    }
  }
  b_tpts.set_size(1, tpts.size(1));
  loop_ub = tpts.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_tpts[i] = tpts[i];
  }
  coder::robotics::core::internal::addFlatSegmentsToPPFormParts(
      b_tpts, coefMat, derivativeBreaks, modCoeffs);
  pp->coefs.set_size(3, derivativeBreaks.size(1) - 1, 6);
  loop_ub = 3 * (derivativeBreaks.size(1) - 1) * 6;
  for (i = 0; i < loop_ub; i++) {
    pp->coefs[i] = modCoeffs[i];
  }
  pp->breaks.set_size(1, derivativeBreaks.size(1));
  loop_ub = derivativeBreaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    pp->breaks[i] = derivativeBreaks[i];
  }
  coder::ppval(pp->breaks, pp->coefs, tvec, r);
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    q[3 * i] = r[3 * i];
    q[3 * i + 1] = r[3 * i + 1];
    q[3 * i + 2] = r[3 * i + 2];
  }
  coder::robotics::core::internal::changeEndSegBreaks(derivativeBreaks, tvec);
  dCoeffs.set_size(modCoeffs.size(0), 6);
  loop_ub = modCoeffs.size(0) * 6;
  for (i = 0; i < loop_ub; i++) {
    dCoeffs[i] = 0.0;
  }
  loop_ub = modCoeffs.size(0);
  for (int b_i{0}; b_i < 5; b_i++) {
    for (i = 0; i < loop_ub; i++) {
      dCoeffs[i + dCoeffs.size(0) * (b_i + 1)] =
          ((6.0 - (static_cast<double>(b_i) + 2.0)) + 1.0) *
          modCoeffs[i + modCoeffs.size(0) * b_i];
    }
  }
  ppd_coefs.set_size(3, derivativeBreaks.size(1) - 1, 6);
  loop_ub_tmp = 3 * (derivativeBreaks.size(1) - 1) * 6;
  for (i = 0; i < loop_ub_tmp; i++) {
    ppd_coefs[i] = dCoeffs[i];
  }
  b_tpts.set_size(1, derivativeBreaks.size(1));
  loop_ub = derivativeBreaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_tpts[i] = derivativeBreaks[i];
  }
  coder::ppval(b_tpts, ppd_coefs, tvec, r);
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    qd[3 * i] = r[3 * i];
    qd[3 * i + 1] = r[3 * i + 1];
    qd[3 * i + 2] = r[3 * i + 2];
  }
  coefMat.set_size(dCoeffs.size(0), 6);
  loop_ub = dCoeffs.size(0) * 6;
  for (i = 0; i < loop_ub; i++) {
    coefMat[i] = 0.0;
  }
  loop_ub = dCoeffs.size(0);
  for (int b_i{0}; b_i < 5; b_i++) {
    for (i = 0; i < loop_ub; i++) {
      coefMat[i + coefMat.size(0) * (b_i + 1)] =
          ((6.0 - (static_cast<double>(b_i) + 2.0)) + 1.0) *
          dCoeffs[i + dCoeffs.size(0) * b_i];
    }
  }
  ppd_coefs.set_size(3, derivativeBreaks.size(1) - 1, 6);
  for (i = 0; i < loop_ub_tmp; i++) {
    ppd_coefs[i] = coefMat[i];
  }
  b_tpts.set_size(1, derivativeBreaks.size(1));
  loop_ub = derivativeBreaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_tpts[i] = derivativeBreaks[i];
  }
  coder::ppval(b_tpts, ppd_coefs, tvec, r);
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    qdd[3 * i] = r[3 * i];
    qdd[3 * i + 1] = r[3 * i + 1];
    qdd[3 * i + 2] = r[3 * i + 2];
  }
}

//
// Arguments    : void
// Return Type  : void
//
void Quinticpolytraj_initialize()
{
}

//
// Arguments    : void
// Return Type  : void
//
void Quinticpolytraj_terminate()
{
}

//
// File trailer for Quinticpolytraj.cpp
//
// [EOF]
//

//
// File: Quinticpolytraj.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Dec-2023 23:22:41
//

#ifndef QUINTICPOLYTRAJ_H
#define QUINTICPOLYTRAJ_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct struct0_T;

// Function Declarations
extern void Quinticpolytraj(const coder::array<double, 2U> &wpts,
                            const coder::array<double, 2U> &tpts,
                            const coder::array<double, 2U> &tvec,
                            const coder::array<double, 2U> &e,
                            coder::array<double, 2U> &q,
                            coder::array<double, 2U> &qd,
                            coder::array<double, 2U> &qdd, struct0_T *pp);

extern void QuinticpolytrajNolimit(
    const coder::array<double, 2U> &wpts, const coder::array<double, 2U> &tpts,
    const coder::array<double, 2U> &tvec, coder::array<double, 2U> &q,
    coder::array<double, 2U> &qd, coder::array<double, 2U> &qdd, struct0_T *pp);

extern void Quinticpolytraj_initialize();

extern void Quinticpolytraj_terminate();

#endif
//
// File trailer for Quinticpolytraj.h
//
// [EOF]
//

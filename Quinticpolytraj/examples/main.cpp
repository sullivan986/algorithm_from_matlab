//
// File: main.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Dec-2023 23:22:41
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "Quinticpolytraj.h"
#include "Quinticpolytraj_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static coder::array<double, 2U> argInit_1xUnbounded_real_T();

static coder::array<double, 2U> argInit_3xUnbounded_real_T();

static double argInit_real_T();

// Function Definitions
//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_1xUnbounded_real_T()
{
  coder::array<double, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 1; idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx1] = argInit_real_T();
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_3xUnbounded_real_T()
{
  coder::array<double, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(3, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 3; idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + 3 * idx1] = argInit_real_T();
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_Quinticpolytraj();
  main_QuinticpolytrajNolimit();
  // Terminate the application.
  // You do not need to do this more than one time.
  Quinticpolytraj_terminate();
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
void main_Quinticpolytraj()
{
  coder::array<double, 2U> q;
  coder::array<double, 2U> qd;
  coder::array<double, 2U> qdd;
  coder::array<double, 2U> tpts_tmp;
  coder::array<double, 2U> wpts_tmp;
  struct0_T pp;
  // Initialize function 'Quinticpolytraj' input arguments.
  // Initialize function input argument 'wpts'.
  wpts_tmp = argInit_3xUnbounded_real_T();
  // Initialize function input argument 'tpts'.
  tpts_tmp = argInit_1xUnbounded_real_T();
  // Initialize function input argument 'tvec'.
  // Initialize function input argument 'e'.
  // Call the entry-point 'Quinticpolytraj'.
  Quinticpolytraj(wpts_tmp, tpts_tmp, tpts_tmp, wpts_tmp, q, qd, qdd, &pp);
}

//
// Arguments    : void
// Return Type  : void
//
void main_QuinticpolytrajNolimit()
{
  coder::array<double, 2U> q;
  coder::array<double, 2U> qd;
  coder::array<double, 2U> qdd;
  coder::array<double, 2U> tpts_tmp;
  coder::array<double, 2U> wpts;
  struct0_T pp;
  // Initialize function 'QuinticpolytrajNolimit' input arguments.
  // Initialize function input argument 'wpts'.
  wpts = argInit_3xUnbounded_real_T();
  // Initialize function input argument 'tpts'.
  tpts_tmp = argInit_1xUnbounded_real_T();
  // Initialize function input argument 'tvec'.
  // Call the entry-point 'QuinticpolytrajNolimit'.
  QuinticpolytrajNolimit(wpts, tpts_tmp, tpts_tmp, q, qd, qdd, &pp);
}

//
// File trailer for main.cpp
//
// [EOF]
//

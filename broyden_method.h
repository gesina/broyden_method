#ifndef BROYDENMETHOD
#define BROYDENMETHOD

/* ************************************************ */
/*                                                  */
/*   FILE: broyden_method.h                         */
/*                                                  */
/*   PROJECT:                                       */
/*   *************                                  */
/*    BROYDEN METHOD                                */
/*                                                  */
/*   Excercise #45 for the lecture                  */
/*   NUMERICAL MATHEMATICS in 2014/15               */
/*   by Prof. Dr. Blank                             */
/*   University of Regensburg                       */
/*                                                  */
/*   AUTHORS:                                       */
/*   *************                                  */
/*     Kerstin Blomenhofer and Gesina Schwalbe      */
/*     Group 30                                     */
/*                                                  */
/* ************************************************ */



//---------------------------------------------------
//
//     Broyden's method
//
//---------------------------------------------------



// struct for return data of broyden_method()
struct x_f_step_flag
{
  double* x;      // x_k for max. k
  double* f;      // f(x_k) 
  int step;       // k
  int flag;       // success indicator:
                    // (2) LU decomposition failed on returned step
                    // (1) maximal iteration step input not enough
                    // (0) successful iteration within tolerance
};

struct x_f_step_flag broyden_method(void (*function)(double*,double*), int, double*, double**, int, double);


#endif

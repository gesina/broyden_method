#ifndef SOLVEEQUATION
#define SOLVEEQUATION

/* ************************************************ */
/*                                                  */
/*   FILE: solve_equation.h                         */
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
//  LU decomposition to solve Ax=b
//
//---------------------------------------------------

// LU DECOMPOSITION
// of given Matrix A, returns completion indicator
int lu_decomposition(double**, int*, int);

// FORWARD SUBSTITUTION
// changes given vector b to z
void forward_substitution(double*, int*, double**, int);

// BACKWARD SUBSTITUTION
// writes solution of Ux=z into given vector x
void backward_substitution(double**, double*, double*, int);

// prepares call of lu_decomposition
//   (init of LU, pi)
// and returns struct with LU, pi, step
int solve_equation(double**, double*, int, double*);

#endif

#ifndef BROYDENFUNCTIONS
#define BROYDENFUNCTIONS

/* ************************************************ */
/*                                                  */
/*   FILE: broyden_functions.h                      */
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
//  Functions to get the zero of
//
//---------------------------------------------------

// function IDs:
/*  (1) linear(): f(x) = x-1
    (2) example_ii(): f(x) = {{(x1+3)(x2^2-7)+18},{sin(x2*exp(x1)-1}}
    (3) example_iii(): f(x) = {{x1+x2-3},{x1^2+x2^2-9}}
*/
#define LINEAR "f(x)=x-1\n"
#define EXAMPLE_II "f(x) = {{(x1+3)(x2^2-7)+18},{sin(x2*exp(x1)-1}}\n"
#define EXAMPLE_III "f(x) = {{x1+x2-3},{x1^2+x2^2-9}}\n"

// LINEAR
// f(x) = x-1
void linear(double*, double*);

// EXAMPLE_II
// f(x) = {{(x1+3)(x2^2-7)+18},{sin(x2*exp(x1)-1}}
void example_ii(double*,double*);

// EXAMPLE_III
// f(x) = {{x1+x2-3},{x1^2+x2^2-9}}
void example_iii(double*, double*);

// PREDEFINITIONS
// (give pointer on vector x, matrix B, maxit and tol to write in)
_Bool ex_ii_predef_x1(double**, double***, double*, int*);
_Bool ex_ii_predef_x2(double**, double***, double*, int*);

_Bool ex_iii_predef_B1(double**, double***, double*, int*);
_Bool ex_iii_predef_B2(double**, double***, double*, int*);

#endif

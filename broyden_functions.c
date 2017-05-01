
/* ************************************************ */
/*                                                  */
/*   FILE: broyden_functions.c                      */
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

#include <stdio.h>   // printf()
#include <math.h>    // pow(), exp(), sin()

#include "broyden_functions.h"
#include "matrix_operations.h"
#include "broyden_output.h"

// LINEAR
// f(x) = x-1
void linear(double* arg, double* res){
  *res = *arg-1;
}

// EXAMPLE_II
// f(x) = {{(x1+3)(x2^2-7)+18},{sin(x2*exp(x1)-1}}
void example_ii(double* arg,double* res) {
  res[0]=(arg[0]+3) * (pow(arg[1],3) -7)+18;
  res[1]= sin(arg[1] * exp(arg[0]) -1);
}


// EXAMPLE_III
// f(x) = {{x1+x2-3},{x1^2+x2^2-9}}
void example_iii(double* arg, double* res) {
  res[0]=arg[0]+arg[1]-3;
  res[1]=pow(arg[0],2)+pow(arg[1],2)-9;
}



// PREDEFINITIONS
_Bool ex_ii_predef_x1(double** x, double*** B, double* tol, int* maxit) {
  *x=init_vector(2);    // init x_0
  if(!*x){return 1;}
  *B=init_matrix(2,2);  // init B_0
  if(!*B){return 1;}

  // set x
  (*x)[0]=-0.5;
  (*x)[1]=1.4;

  // set B
  (*B)[0][0]=-4.256;
  (*B)[0][1]=-20.58;
  (*B)[1][0]=0.839499;
  (*B)[1][1]=0.599642;

  // set tol to 10^(-10)
  *tol=0.0000000001;

  // set maxit
  *maxit=50;
  
  // output for user
  printf("You chose the predefined values:\n");
  printf("  Starting point x_0:\n");
  print_vector(*x, 2);
  printf("  Starting differential B_0:\n");
  print_matrix(*B, 2,2);
  printf("  Tolerance:"MATRIX_ENTRY"\n", *tol);
  printf("  Maximum number of steps:  %i\n", *maxit);

  return 0;
}


_Bool ex_ii_predef_x2(double** x, double*** B, double* tol, int* maxit) {
  *x=init_vector(2);    // init x_0
  if(!*x){return 1;}
  *B=init_matrix(2,2);  // init B_0
  if(!*B){return 1;}

  // set x
  (*x)[0]=-0.14;
  (*x)[1]=-1.47;

  // set B to
  (*B)[0][0]=-10.1765;
  (*B)[0][1]=-20.3557;
  (*B)[1][0]=0.83026;
  (*B)[1][1]=-0.564803;

  // set tol
  *tol=0.0000000001;

  // set maxit
  *maxit=50;

  // output for user
  printf("You chose the predefined values:\n");
  printf("  Starting point x_0:\n");
  print_vector(*x, 2);
  printf("  Starting differential B_0:\n");
  print_matrix(*B, 2,2);
  printf("  Tolerance:"MATRIX_ENTRY"/n", *tol);
  printf("  Maximum number of steps:  %i\n", *maxit);

  return 0;
}


_Bool ex_iii_predef_B1(double**x, double*** B, double* tol, int* maxit) {
  *x=init_vector(2);    // init x_0
  if(!*x){return 1;}
  *B=init_matrix(2,2);  // init B_0
  if(!*B){return 1;}

  // set x
  (*x)[0]=0;
  (*x)[1]=1;

  // set B to Id
  (*B)[0][0]=1;
  (*B)[0][1]=0;
  (*B)[1][0]=0;
  (*B)[1][1]=1;

  // set tol
  *tol=0.0000000001;

  // set maxit
  *maxit=50;

  // output for user
  printf("You chose the predefined values:\n");
  printf("  Starting point x_0:\n");
  print_vector(*x, 2);
  printf("  Starting differential B_0:\n");
  print_matrix(*B, 2,2);
  printf("  Tolerance:"MATRIX_ENTRY"\n", *tol);
  printf("  Maximum number of steps:  %i\n", *maxit);

  return 0;
}


_Bool ex_iii_predef_B2(double** x, double*** B, double* tol, int* maxit) {
  *x=init_vector(2);    // init x_0
  if(!*x){return 1;}
  *B=init_matrix(2,2);  // init B_0
  if(!*B){return 1;}

  // set x
  (*x)[0]=0;
  (*x)[1]=1;

  // set B to Id
  (*B)[0][0]=1;
  (*B)[0][1]=1;
  (*B)[1][0]=-79999999999/100000;
  (*B)[1][1]=-79999999999/100000;

  // set tol
  *tol=0.0000000001;

  // set maxit
  *maxit=50;

  // output for user
  printf("You chose the predefined values:\n");
  printf("  Starting point x_0:\n");
  print_vector(*x, 2);
  printf("  Starting differential B_0:\n");
  print_matrix(*B, 2,2);
  printf("  Tolerance:"MATRIX_ENTRY"\n", *tol);
  printf("  Maximum number of steps:  %i\n", *maxit);

  return 0;
}

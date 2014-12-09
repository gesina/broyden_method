
/* ************************************************ */
/*                                                  */
/*   FILE: functions.h                              */
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


// LINEAR
// f(x) = x-1
void linear(double* arg, double* res)
{
  *res = *arg-1;
}

// EXAMPLE_II
// f(x) = {{(x1+3)(x2^2-7)+18},{sin(x2*exp(x1)-1}}
void example_ii(double* arg,double* res)
{
  res[0]=(arg[0]+3) * (pow(arg[1],3) -7)+18;
  res[1]= sin(arg[1] * exp(arg[0]) -1);
}

// EXAMPLE_III
// f(x) = {{x1+x2-3},{x1^2+x2^2-9}}
void example_iii(double* arg, double* res)
{
  res[0]=arg[0]+arg[1]-3;
  res[1]=pow(arg[0],2)+pow(arg[1],2)-9;
}


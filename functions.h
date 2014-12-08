
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
double* linear(double* arg)
{
  *arg = *arg-1;
  return arg;
}

// EXAMPLE_II
// f(x) = {{(x1+3)(x2^2-7)+18},{sin(x2*exp(x1)-1}}
double* example_ii(double* arg)
{
  double* y=init_vector(2);
  
  y[0]=(arg[0]+3) * (pow(arg[1],3) -7)+18;
  y[1]= sin(arg[1] * exp(arg[0]) -1);

  return y;
}

// EXAMPLE_III
// f(x) = {{x1+x2-3},{x1^2+x2^2-9}}
double* example_iii(double* arg)
{
  double* y=init_vector(2);

  y[0]=arg[0]+arg[1]-3;
  y[1]=pow(arg[0],2)+pow(arg[1],2)-9;

  return y;
}


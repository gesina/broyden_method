
/* ************************************************ */
/*                                                  */
/*   FILE: broyden_method.c                         */
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

#include <stdio.h>              // printf()
#include <math.h>
#include <float.h>              // DBL_EPSILON: minimum double precision

#include "broyden_method.h"
#include "broyden_file.h"
#include "solve_equation.h"
#include "broyden_functions.h"
#include "matrix_operations.h"

struct x_f_step_flag broyden_method(void (*function)(double*,double*), int dim, double* x, double** B, int maxit, double tol)
{
  // INIT VARIABLES
  //---------------------------------------------------
  // struct for return values with default values
  struct x_f_step_flag return_struct = {NULL, NULL, maxit, 0};
  
  double* x_= init_vector(dim); // x_(k+1)
  double* p = init_vector(dim); // p_k = x_(k+1)-x_k
  double  scprodp = -1;         // ||p_k||^2 = p_k^T*p_k
  double* f = init_vector(dim); // f(x_k)
  double* f_= init_vector(dim); // f(x_(k+1))
  
  double* x_x = init_vector(dim); // to save x_(k+1)-x_k
  double* temp_vec = NULL; // for vector-switching

  // values to print in file (with default)
  double normf_, normxx_=10, conv;  // ||f(x_k)||, ||x_k-x_(k-1)|| , rate of convergence

  // check on success
  if(!x_ || !p || !f || !f_ ) // allociation error?
    {return_struct.flag=-1; return return_struct;}
  

  // FIRST STEP 
  //---------------------------------------------------
  // f = f(x_k)
  function(x, f);

  
  // ACTUAL BROYDEN METHOD
  //---------------------------------------------------
  // recur until maxit (or tol, see below) reached
  for(return_struct.step=0; return_struct.step<maxit; return_struct.step++)
    {
      // p=[B_k]^(-1)*f(x_k)
      if(solve_equation(B, f, dim, p))
	{// if LU decomposition failed: return
	  return_struct.flag=2;
	  break;
	};

      // x_(k+1)=x_k-p_k
      for(int i=0;i<dim;i++){x_[i]= x[i]-p[i];}

      // f_ = f(x_(k+1))
      function(x_, f_);

      // B_(k+1) = B_k - 1/(p_k^T*p_k)*{(f(x_(k+1))-f(x_k))+B_k*p_k}*p_k^T 
      scprodp = scprod_vector(p, dim); // ||p_k||^2
      for(int i=0;i<dim; i++)      // rows
	{
	  // B_(k+1) =  B_k - 1/(p_k^T*p_k) * f(x_(k+1))*p_k^T
	  for(int j=0;j<dim;j++)   // columns
	    {
	      B[i][j] -= (1/scprodp) * p[j] * f_[i];
	    }
	}

      
      // PRINT FILE ENTRY
      //------------------------------
      // ||f(x_(k+1))||
      normf_= pow(scprod_vector(f_, dim), 0.5);

      // conv = (log(||x_(k+1)-x_k||)/log(||x_k-x_(k-1)||))
      conv=log(normxx_);                           // conv = log||x_k-x_(k-1)||
      for(int i=0;i<dim;i++){x_x[i]=x_[i]-x[i];}   // x_x = x_(k+1)-x_k
      normxx_= pow(scprod_vector(x_x, dim),0.5);   // normxx_=||x_(k+1)-x_k||
      conv=log(normxx_)/conv;                      // conv= log(||x_(k+1)-x_k||)/conv

      // actual printing (with check on success)
      if(!print_into_file(return_struct.step, normf_, normxx_, conv))
	{printf("error while printing ...\n");}

      
      // SWITCHING TO NEXT STEP VECTORS
      //---------------------------------------------------
      // x_(k+1) ~> x_k
      temp_vec = x;
      x = x_;
      x_=temp_vec;  // entries will be overwritten in next step
      
      // f(x_(k+1)) ~> f(x_k)
      temp_vec = f;
      f = f_;
      f_= temp_vec;  // entries will be overwritten in next step
      

      // TOLERANCE CHECK
      //---------------------------------------------------
      // tolerance reached or zero found?
      if(fabs(normxx_-tol) <= DBL_EPSILON || fabs(normf_) <= DBL_EPSILON )
	{
	  return_struct.flag=0;
	  break;
	}      
    }

  
  // prepare return values
  return_struct.x=x;
  return_struct.f=f;

  // free created vectors
  free_memory_vector(x_x);
  free_memory_vector(x_);
  free_memory_vector(p);
  free_memory_vector(f); free_memory_vector(f_);

  
  return return_struct; // all well
}

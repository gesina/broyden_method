
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
double* linear(double* arg, int dim) // for reusability: take dimension as argument
{
  *arg = *arg-1;
  return arg;
}

double* example_ii(double* arg, int dim)  // for reusability: take dimension as argument
{
  double* y=init_vector(2);
  
  y[0]=(arg[0]+3) * (pow(arg[1],3) -7)+18;
  y[1]= sin(arg[1] * exp(arg[0]) -1);

  return y;
}

double* example_iii(double* arg, int dim) // for reusability: take dimension as argument
{
  double* y=init_vector(2);

  y[0]=arg[0]+arg[1]-3;
  y[1]=pow(arg[0],2)+pow(arg[1],2)-9;

  return y;
}


double* matrix_test(double* arg, double** B, int dim) // for reusability: take dimension as argument
{
  // vector to matrix
  double** v= init_matrix(3,1);
  if( v!= NULL)
    {
      for(int i=0; i<3; i++)
	{
	  v[i][0]= arg[i];
	}
      double** C= mult_matrix(B, v, 3,3,1);
      
      // and back to vector
      double* c= init_vector(3);
      if(C!= NULL && c!= NULL) // multiplikation worked?
	{
	  for(int i=0; i<3; i++)
	    {
	      c[i] = C[i][0];
	    }
	}
      free_memory_matrix(C, 3, 1);
      return c;
    }
  return NULL; 
}


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


struct x_f_step_flag broyden_method(void (*function)(double*,double*), int dim, double* x, double** B, int maxit, double tol)
{
  printf("\nBROYDEN\nwith parameters: x:%f, dim:%i, B:%x, maxit:%i, tol:%f\n\n", *x, dim, B, maxit,tol);
  // struct for return values
  struct x_f_step_flag return_struct;
  return_struct.step=maxit;  // default step number
  return_struct.flag=1;
  
  double* x_= init_vector(dim); // x_(k+1)
  double* p = init_vector(dim); // p_k = x_(k+1)-x_k
  double normp;                  // ||p_k|| = p_k^T*p_k
  double* f = init_vector(dim); // f(x_k)
  double* f_= init_vector(dim); // f(x_(k+1))
  
  double* x_x=init_vector(dim); // to save x_(k+1)-x_k
  double* temp_vec=NULL; // for vector-switching
  
  // ||f(x_k)||, ||x_k-x_(k-1)|| , rate of convergence
  double normf_, normxx_=10, conv; // values to print in file 
 
  // f = f(x_(k+1))
  function(x, f); printf("\nstart value: f(x_k)=%f", *f);

  
  if(!x_ || !p || !f || !f_ ){return_struct.flag=-1; return return_struct;} // allociation error?

  for(int k=0; k<maxit; k++){  // recur until maxit (or tol, see below) reached
    printf("\nSTEP %i\n---------------------------\n", k);
    
    /* // f = f(x_k) */
    /* function(x, f); printf("\nf(x_k)=%f", *f); */

    // p=-[B_k]^(-1)*f(x_k)
    if(solve_equation(B, f, dim, p)){break;}; // p = [B_k]^(-1) * f(x_k)
    for(int i=0;i<dim;i++){p[i]=-p[i];} // p=-p
    
    // x_(k+1)=x_k+p_k
    for(int i=0;i<dim;i++){x_[i]= x[i]+p[i];}

      // f_ = f(x_(k+1))
      function(x_, f_);

      // B_(k+1) = B_k + 1/(p_k^T*p_k)*{(f(x_(k+1))-f(x_k))-B_k*p_k}*p_k^T 
      normp = norm_vector(p, dim); // ||p_k||
      for(int i=0;i<dim; i++)  // rows
      	{
      /* 	  /\* for(int j=0;j<dim;j++) // columns *\/ */
      /* 	  /\*   { *\/ */
      /* 	  /\*     B[i][j] = B[i][j]+ (1/pow(normp,2)) * p[j] * (f_[i]-f[i]-f[i]); *\/ */
      /* 	  /\*   } *\/ */
	  
      	  // minimized errors: substraktion last
      	  // B_(k+1) =  B_k + 1/(p_k^T*p_k) * f(x_(k+1))*p_k^T
      	  for(int j=0;j<dim;j++) // columns
      	    {
      	      B[i][j] += (1/pow(normp,2)) * p[j] * f_[i];
      	    }
      	  //  B_(k+1) =  B_k + 1/(p_k^T*p_k) * f(x_(k+1))*p_k^T */
      	  //           - B_k + 1/(p_k^T*p_k) * {f(x_k))+B_k*p_k}*p_k^T
      	  /* for(int j=0;j<dim;j++) // columns */
      	  /*   { */
      	  /*     B[i][j] -= (1/pow(normp,2)) * p[j] * 2 * f[i]; */
      	  /*   } */
      	}

      
      // PRINT FILE ENTRY
      // ||f(x_(k+1))||
      normf_= norm_vector(f_, dim);

      // conv = (log(||x_(k+1)-x_k||)/log(||x_k-x_(k-1)||))
      conv=log(normxx_);             // conv = log||x_k-x_(k-1)||
      for(int i=0;i<dim;i++){x_x[i]=x_[i]-x[i];} // temp_vec=x_(k+1)-x_k
      normxx_=norm_vector(x_x, dim); // normxx_=||x_(k+1)-x_k||
      conv=log(normxx_)/conv;        // conv= log(||x_(k+1)-x_k||)/conv

      // actual printing
      printf("values:\n");
      printf("x_(k+1)=%f\n",*x_);
      printf("f(x_k)=%f\n", *f);
      printf("f(x_(k+1))=%f\n", *f_);
      printf("p_k=%f\n",*p);
      printf("normp:%f\n", normp);
      printf("B:%f\n",**B);
      
      printf("for file:\n");
      //printf("k:%i, |f(x_k)|:%f, |x_(k+1)-x_k|:%f, conv:%f\n",k,normf_,normxx_,conv);
      if(!print_into_file(k, normf_, normxx_, conv)){printf("error while printing ...\n");}

      
      // SWITCHING TO NEXT STEP VECTORS
      // x_(k+1) ~> x_k
      temp_vec = x;
      x = x_;
      x_=temp_vec;  // entries will be overwritten in next step
      
      // f(x_(k+1)) ~> f(x_k)
      temp_vec = f;
      f = f_;
      f_= temp_vec;  // entries will be overwritten in next step


      // TOLERANCE CHECK
      // tolerance reached or zero found?
      if(fabs(normxx_-tol) <= DBL_EPSILON || fabs(normf_) <= DBL_EPSILON )
	{
	  return_struct.step=k;
	  return_struct.flag=0;
	  break;
	}
      
  }

  // give step results from output-file:
  //print_file();

  // prepare return values
  return_struct.x=x;
  return_struct.f=f;
  
  
  return return_struct; // all well
}

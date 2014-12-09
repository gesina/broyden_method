
/* ************************************************ */
/*                                                  */
/*   FILE: math_operations.h                        */
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
//   Matrix math operations
//
//---------------------------------------------------





// copy function for matrices
void copy_matrix(double** A, double** B,int m, int n) // copy matrix A into B
{
  //printf("in copymatrix with A:%f, B:%f, m:%i, n:%i",**A,**B,m,n);
  // rows
  for (int i=0; i<m; i++)
    {
      //columns
      for ( int j=0; j<n; j++)
	{
	  B[i][j] = A[i][j];
	}
    };
}



// copy function for vectors
void copy_vector(double* a, double* b ,int dim) // copy vector a into b
{
  for (int i=0; i<dim; i++)
    {
      *(a+i) = *(b+i);
    }
}


// multiplication of matrices
double** mult_matrix(double** A, double** B, int m, int n, int l)
//m Zeilen von A, n Spalten von A und Zeilen von B, l Spalten von B
{
  printf("\nm is %i, n is %i, k is %i\n",m,n,l);
  double** C=init_matrix(m, l);
  
  for(int i=0; i<m; i++) //Zeilen
    {
    for(int k=0; k<l; k++) //Spalten
    {
    	for(int j=0; j<n; j++) 
    	{
    	  C[i][k] += A[i][j] * B[j][k];
    	}
    }
  }
  
  return C;
}


// addition of matrices
double** add_matrix(double** A, double** B, int m, int n)
{
  double** C=init_matrix(m, n);
  
  for(int i=0; i<m; i++) //Zeilen
  {
    for(int j=0; j<n; j++) //Spalten
      {
  	  C[i][j] = A[i][j] + B[i][j];
      }
  }

  return C;
}



// norm of vectors (l_2-norm)
double norm_vector(double* x, int dim)
{
  double norm=0;
  for(int i=0; i<dim; i++)
    {
      norm += pow(x[i],2);
    }
  norm=sqrt(norm);
  return norm;
}


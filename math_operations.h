
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
  // rows
  for (int i=0; i<m; i++)
    {
      //columns
      for ( int j=0; j<n; j++)
	{
	  *(*(B+i)+j) = *(*(A+i)+j);
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
void mult_matrix(double** A, double** B, int m, int n) //m Zeilen, n Spalten
{
  double** C=init_matrix(m, m);
  
  for(int i=0; i<m; i++) //Zeilen
  {
    for(int K=0; k<n; k++) //Spalten
    {
    	for(int j=0; j<n; j++) 
    	{
    	  C[i][k] += A[i][j] * B[j][k];
    	}
    }
  }
}


// addition of matrices
void add_matrix(double** A, double** B, int m, int n)
{
  double** C=init_matrix(m, n);
  
  for(int i=0; i<m; i++) //Zeilen
  {
    for(int j=0; j<n; j++) //Spalten
      {
  	  C[i][j] = A[i][j] + B[i][j];
      }
  }
}



}

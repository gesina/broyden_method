
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
void copy_matrix(double* a, double* b ,int dim) // copy matrix A into B
{
  for (int i=0; i<dim; i++)
    {
      *(b+i) = *(a+i);
    }
}


// multiplication of matrices


// addition of matrices

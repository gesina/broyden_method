
/* ************************************************ */
/*                                                  */
/*   FILE: print.h                                  */
/*                                                  */
/*   PROJECT:                                       */
/*   *************                                  */
/*    LU-DECOMPOSITION WITH PIVOTING                */
/*      and                                         */
/*    SOLVING OF A LINEAR EQUATION SYSTEM           */
/*                                                  */
/*   Excercise #20 for the lecture                  */
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
//  All output functions
//
//---------------------------------------------------



// greetings +  instructions
void print_init()
{
  printf("\n****************************************************");
  printf("\n*                                                  *");
  printf("\n*    LU-DECOMPOSITION WITH PIVOTING                *");
  printf("\n*                 and                              *");
  printf("\n*    SOLVING OF A LINEAR EQUATION SYSTEM           *");
  printf("\n*                                                  *");
  printf("\n****************************************************\n");
};

// bye bye
void print_exit()
{
  printf("\nThanks for using this little programm.\n");
  printf("\n      Yours sincerely");
  printf("\n             Kerstin Blomenhofer");
  printf("\n             Gesina Schwalbe\n\n");
}

// matrix
void print_matrix(double** A, int m, int n)
{
  //rows
  for (int i=0; i<m; i++)
    {
      //columns
      for(int j=0; j<n; j++)
	{
	  printf("  %6.3f  ", *(*(A+i)+j)); // simple print: total 6 numbers, 3 after comma
	}
      printf("\n");  // begin new row
    }
}

// vector
void print_vector(double* b, int dim)
{
  for(int i=0; i<dim; i++)
    {
      printf("   %f \n", *(b+i));
    }
}
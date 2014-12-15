
/* ************************************************ */
/*                                                  */
/*   FILE: broyden_output.c                         */
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
//  All output functions
//
//---------------------------------------------------

#include<stdio.h>            // printf(), scanf()

#include"broyden_output.h"



// greetings +  instructions
void print_init()
{
  printf("\n****************************************************");
  printf("\n*                                                  *");
  printf("\n*     ITERATION of a function's ZERO               *");
  printf("\n*                   with                           *");
  printf("\n*             BROYDEN'S METHOD                     *");
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
	  printf(MATRIX_ENTRY, A[i][j]);
	}
      printf("\n");  // begin new row
    }
}


// vector
void print_vector(double* b, int dim)
{
  for(int i=0; i<dim; i++)
    {
      printf(MATRIX_ENTRY "\n", b[i]);
    }
}

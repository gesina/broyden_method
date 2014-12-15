
/* ************************************************ */
/*                                                  */
/*   FILE: broyden_input.c                          */
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
//   All input functions
//
//---------------------------------------------------

#include <stdio.h>          // printf(), scanf()
#include <string.h>         // strchr()

#include "broyden_input.h"  // init, free & copy functions 
#include "broyden_output.h" // print_matrix(), print_vector(), MATRIX_ENTRY


// GET-FUNCTIONS
// ask user for input of yes or no
char get_yesno()
{
  _Bool b=1;    // helper bool
  char c=' ';
  printf(" Please enter yes (y) or no (n):  ");
   do
    {
      scanf("%c", &c);                            // get user input
      if ( c=='y' || c=='n' ) {b=0;}              // ok --> quit
      else if (c=='\n') {b=1;}                    // newline --> again
      else {printf("  Please enter y or n :  ");} // not ok --> repeat
    }
  while(b);

  return c;     // return y or n
}


// gets function ID from user
char get_function()  // ask user for input of yes or no
{
  _Bool b=1;    // helper bool
  char c=' ';
  printf("\nPlease enter one of the following%s:  ", FUNCTION_OPTIONS_PRINT);
  do
    {
      scanf("%c", &c);                   // get user input
      // check, whether input is in FUNCTION_OPTIONS-string
      if ( strchr(FUNCTION_OPTIONS, c) != NULL ) {
	printf("You entered option %c. Take it?\n", c);
	if(get_yesno()=='y'){b=0;}       // ok and wanted --> quit
      }
      else if( c=='\n' ){b=1;}           // newline --> again
      else {                             // not ok --> repeat
	printf("Please enter only one of the following %s: ", FUNCTION_OPTIONS_PRINT);          
      }
    }
  while(b);
  
  return c;     // return a function ID
}


// gets tolerance value from user
double get_tolerance()  // gets the convergence tolerance
{

  double tol = -1;   // tolerance to return
  _Bool b=1;         // test bool for while-loop

  printf("\nPlease enter the tolerance:  ");
  do  // as long as input doesn't make sense: repeat
    {
      scanf("%lf", &tol); // user read in
      // verify input
      if ( tol <= 0 )// not ok --> try again
	{
	  printf("\n  Please enter a tolerance greater than zero!\n");
	  printf("   Your input: %f\n", tol);
	  printf("Try again:  "); // ... and give some warning
	}
      else {        // ok and wanted --> return
	printf("You entered for tolerance %f. Take it?\n", tol);
	if(get_yesno()!='y'){
	  printf("Then try again: ");
	  b=0;
	}
      }
    }
  while(b);

  return tol;

}


// gets maximum number of iteration steps
int get_maxit()
{

  int maxit = -1; // number of steps to return
  _Bool b=1;      // test bool for while-loop

  
  printf("\nPlease enter the maximum number of iteration steps:  ");
  do  // as long as input doesn't make sense: repeat
    {
      scanf("%d", &maxit); // user read in

      // verify input
      if ( maxit <= 0 )    // not ok --> repeat
	{
	  printf("  Please enter a maximum number of iterations greater than zero!\n");
	  printf("   Your input: %i\n", maxit);
	  printf("Try again:  "); // give some warning
	};
    }
  while(b);

  return maxit;
}


// gets+sets entries of given matrix A
void set_matrix(double** A, int m, int n)
{
  _Bool b=1;      // test bool for while-loop
  char c=' ';     // helper character

  printf("\nDimension for set_matrix: %i x %i\n" , m, n);
  printf("Please enter the matrix entries separately.\n");
  do  // as long as input doesn't make sense: repeat
    {
      for (int i=0; i<m; i++)
	{
	  printf(" Enter row #%i:\n", i+1);
	  
	  // read entries in
	  for ( int j=0; j<n; j++)
	    {
	      scanf("%lf", &A[i][j]); // user read in
	    }
	  
	  // show full row:
	  printf("Row #%i: ", i+1);
	  for (int k=0; k<n; k++)
	    {
	      printf(MATRIX_ENTRY, A[i][k]);
	    }
	}

      // ask, wether to continue or to try again  
      printf("\nYour entries have produced this matrix:\n");
      print_matrix(A,m,n);
      printf("Take these entries?\n");
      
      c = get_yesno();
      if ( c=='y' ) { b=0;}
      else {printf("\nTry again and enter the first row:\n");}
      
    }
  while(b);

}


// gets+sets entries of given vector b
void set_vector(double* b, int dim)
{
  _Bool g=1;      // test bool for while-loop
  char c=' ';     // helper character

  printf("\nPlease enter the entries of the vector: \n");
  do  // as long as input doesn't make sense: repeat
    {
      // read entries in
      for ( int i=0; i<dim; i++)
	{
	  scanf("%lf", &b[i]); // user read in
	}
	 
      // ask, wether to continue or to try again  
      printf("\nYour entries have produced this vector:\n");
      print_vector(b, dim);
      printf("Take these entries?");
      
      c = get_yesno();
      if ( c=='y' ) { g=0;}
      else {printf("\nTry again and enter the vector:\n");}
    }
  while(g);

}



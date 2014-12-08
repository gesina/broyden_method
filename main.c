
/* ************************************************ */
/*                                                  */
/*   FILE: main.c                                   */
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
//  Main executive file for implementation of
//     Broyden's method
//
//---------------------------------------------------


// include all needed libraries and predefinitions
#include "includes.h"


// main function
int main(void)
{

  // greeting
  print_init();


 
  // get tolerance
  tolerance = get_tolerance();
  // last check for correct dimension:
  if( tolerance <= 0 ) {
    printf("Error with tolerance, tolerance is %f", tolerance);
    return 3; // tolerance error
  }
  printf("You entered tolerance %f", tolerance);
  
  double* (*function)(double*);
  // get function
  char c= get_function();
  switch(c){
  case '1':
    function=&linear;
    dimension=1; printf("dimension is %d", dimension);
    printf("%s", LINEAR);
    break;
  case '2':
    function=&example_ii;
    dimension=2;
    printf("%s", EXAMPLE_II);
    break;
  case '3':
    function=&example_iii;
    dimension=2;
    printf("%s", EXAMPLE_III);
    break;
  default:printf("\n taking default function\n");
    function=&linear;
    dimension=1;
  }

  //for LU decomposition test
  /* dimension=get_tolerance();*/
  

  // get start value of x
  double* x = init_vector(dimension);
  if (!x) {return 2;}    // error with allociation?
  printf("\nThe start value for the iteration is needed.");
  set_vector(x, dimension);
  
  // get start value of differential
  double** B =  init_matrix(dimension, dimension);
  printf("\nThe start value for the differential is needed.");
  if (!B) {return 2;}    // error with allociation?
  set_matrix(B, dimension, dimension);     // get actual input from user
  
  
  // BROYDEN'S METHOD
  //--------------------------------------------------
  
  printf("\n\nNow we will start iterating the zero of ...");

  // TESTS
  // LU decomposition test
  /* double* z= init_vector(dimension); */
  /* printf("Number of steps: %d", solve_equation(B, x, dimension, z)); */

  // test of example_ii(i)
  /* print_vector(x, dimension); */
  /* double* z= function(x, dimension); */
  /* print_vector(x, dimension); */

  // test of matrix operations
  /* int m,n; */
  /* printf("\nm: "); */
  /* m=get_tolerance(); */
  /* printf("\nn: "); */
  /* n=get_tolerance(); */
  /* printf("\nmatrix A: "); */
  /* double** A = init_matrix(n,m); set_matrix(A, m,n); */
  /* double** B = init_matrix(n,m); set_matrix(B,m,n); */

  /* print_matrix(add_matrix(A,B,m,n),m,n); */

  x=function(x);
  // check on success
  
  
  printf("\n\nSOLUTION:\n");
  printf("***********************************************************\n");
  print_vector(x, dimension);            // print results



  
  
  // last but not least:
  free_memory_matrix(B, dimension, dimension);
  free_memory_vector(x);


  // Bye, bye
  print_exit();


  return 0;
}

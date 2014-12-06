
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
  if( tol <= 0 ) {
    printf("Error with tolerance, tolerance is %d", tolerance);
    return 3; // tolerance error
  }
  
  double (*function)(double);
  // get function
  switch(get_function()){
  case 1:
    function=linear;
    dimension=1;
    printf("%s", LINEAR);
    break;
  case 2:
    function=example_ii;
    dimension=2;
    printf("%s", EXAMPLE_II);
    break;
  case 3:
    function=example_iii;
    dimension=2;
    printf("%s", EXAMPLE_III);
    break;
  default: function=linear;
  }
  
  // get start value of x
  double* x = init_vector(dimension);
  if (!x) {return 2;}    // error with allociation?
  printf("\nThe start value for the iteration is needed.");
  set_vector(x, dimension);
  
  // get start value of differential
  double** B =  init_matrix(dimension);
  printf("\nThe start value for the differential is needed.");
  if (!B) {return 2;}    // error with allociation?
  set_matrix(B, dimension);     // get actual input from user
  
  
  
  // BROYDEN'S METHOD
  //--------------------------------------------------
  
  printf("\n\nNow we will start iterating the zero of ...");

  
  // check on success

  
  printf("\n\nSOLUTION:\n");
  printf("***********************************************************\n");
  print_vector(x, dimension);            // print results



  
  
  // last but not least:
  free_memory_matrix(B, dimension);
  free_memory_vector(x);


  // Bye, bye
  print_exit();


  return 0;
}


/* ************************************************ */
/*                                                  */
/*   FILE: broyden_main.c                           */
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

// LIBRARIES
#include <stdio.h>     // printf()

#include "broyden_main.h"
#include "broyden_input.h"
#include "broyden_output.h"
#include "broyden_method.h"
#include "broyden_functions.h"
#include "matrix_operations.h"
#include "broyden_file.h"

// main function
int main(void)
{
  // GREETING
  //--------------------------------------------------
  print_init();

  
  // INIT OF VARIABLES (with default values)
  //--------------------------------------------------
  double* x = NULL;      // init x_0 (startvalue)
  double** B= NULL;      // init B_0 (startvalue of differential)  
  int dimension=-1;      // dimension of chosen function (always f:R^m-->R^m)
  int maxit=-1;          // maximum number of iterations
  double tolerance=-1;   // tolerance in which to find solution
  void (*function)(double*, double*); // pointer on function to use

  
  // GET FUNCTION
  //--------------------------------------------------
  _Bool only_predef=0;   // helper bool (whether predefinitions are chosen)
  char c= get_function();// chosen function ID
  switch(c){
  case '1':
    // (1) linear: f(x) = x-1
    function=&linear;
    dimension=1;
    printf("The function will be:  %s\n", LINEAR);
    break;
  case '2':
    // (2): f(x) = {{(x1+3)(x2^2-7)+18},{sin(x2*exp(x1)-1}}
    function=&example_ii;
    dimension=2;
    printf("The function will be:  %s\n", EXAMPLE_II);
    printf("Do you want to take the predefined values?\n");
    if(get_yesno()=='y'){   // take predefined values?
      only_predef=1;        // yes
      x=init_vector(dimension);
      if(!x){return 2;}
      printf("Take first one? (y=first, n=second)\n");
      if(get_yesno()=='y'){   // first example
	if(ex_ii_predef_x1(&x,&B,&tolerance,&maxit)){return 2;}
      }
      else {                  // second example
	if(ex_ii_predef_x2(&x,&B,&tolerance,&maxit)){return 2;}	
      }
    }
    break;
  case '3':
    // (3): f(x) = {{x1+x2-3},{x1^2+x2^2-9}}:
    function=&example_iii;
    dimension=2;
    printf("The function will be:  %s\n", EXAMPLE_III);
    printf("Do you want to take the predefined values?\n");
    if(get_yesno()=='y'){  // take predefined values?
      only_predef=1;       // yes
      x=init_vector(dimension);
      if(!x){return 2;}
      printf("Take first one? (y=first, n=second)\n");
      if(get_yesno()=='y'){   // first example
	if(ex_iii_predef_B1(&x,&B,&tolerance,&maxit)){return 2;};
      }
      else {                  // second example
	if(ex_iii_predef_B2(&x,&B,&tolerance,&maxit)){return 2;};
      }
    }
    break;
  default:printf("\n taking default function\n");
    // default: linear
    function=&linear;
    dimension=1;
  }


  // GET VALUES (if not predefined chosen)
  //--------------------------------------------------
  if(!only_predef)
    {
      // get start value of x
      x = init_vector(dimension);
      printf("\nThe start value for the iteration is needed.\n");
      set_vector(x, dimension);
  
      // get start value of differential
      B =  init_matrix(dimension, dimension);
      if(!B){return 2;}
      printf("\nThe start value for the differential is needed.\n");
      set_matrix(B, dimension, dimension);     // get actual input from user

      // get tolerance
      tolerance = get_tolerance();  
      // last check whether tolerance senseful
      if( tolerance <= 0 ) {
	printf("Error with tolerance, tolerance is %f\n", tolerance);
	return 3; // tolerance error
      }
      printf("You entered tolerance %f\n", tolerance);
 
      // get maximum number of iteration steps
      maxit = get_maxit();
    }

  
  // OUTPUT FILE INIT and return if it failes
  //--------------------------------------------------
  if(!init_file()){return 4;}


  // BROYDEN'S METHOD
  //--------------------------------------------------
  
  printf("\n\nStarting to iterate ...\n");
  struct x_f_step_flag result = broyden_method(function,dimension,x,B,maxit,tolerance);
  
  // check on success
  if(result.flag==-1){       // allociation error?
    printf("Sorry, had to break!\n\n"); print_exit(); return 2;
  }
  else if(result.flag==1){   // more steps?
    printf("\n(More iteration steps would have been needed!!)\n");
  }
  else if(result.flag==2){   // LU decomposition failed?
    printf("LU decomposition failed at step %d!!\n", result.step);
  }
  
  printf("\nSOLUTION after %i steps:\n", result.step);
  printf("***********************************************************\n");
  print_vector(result.x, dimension);    // print results


  // FREE MEMORY
  //--------------------------------------------------
  free_memory_matrix(B, dimension, dimension);
  free_memory_vector(x);


  // Bye, bye
  //--------------------------------------------------
  print_exit();
  return 0;
}

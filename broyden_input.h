#ifndef BROYDENINPUT
#define BROYDENINPUT

/* ************************************************ */
/*                                                  */
/*   FILE: broyden_input.h                          */
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

#define FUNCTION_OPTIONS "123"
#define FUNCTION_OPTIONS_PRINT "\n  (1) f(x)=x-1\n \
 (2) f(x) = {{(x1+3)(x2^2-7)+18},{sin(x2*exp(x1)-1}}\n \
 (3) f(x) = {{x1+x2-3},{x1^2+x2^2-9}}\n"

// GET-FUNCTIONS
// ask user for input of yes or no
char get_yesno();  

// ask user for input of the function to find the zero of
char get_function();

// gets the convergence tolerance
double get_tolerance();

// gets maximum number of iteration steps
int get_maxit();

// gets+sets entries of given matrix
void set_matrix(double**, int, int);

// gets+sets entries of given vector
void set_vector(double*, int);


#endif

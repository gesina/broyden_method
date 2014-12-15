#ifndef BROYDENOUTPUT
#define BROYDENOUTPUT

/* ************************************************ */
/*                                                  */
/*   FILE: broyden_output.h                         */
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


#define MATRIX_ENTRY "\t%16.12f"

// greetings +  instructions
void print_init();

// bye bye
void print_exit();

// matrix
void print_matrix(double**, int, int);

// vector
void print_vector(double*, int);


#endif

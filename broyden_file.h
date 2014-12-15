#ifndef BROYDENFILE
#define BROYDENFILE

/* ************************************************ */
/*                                                  */
/*   FILE: broyden_file.h                           */
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
//  Output-file management
//
//---------------------------------------------------

#define OUTPUT_FILE "broyden_method_output.txt" // output for step results

// OUTPUT
_Bool print_into_file(int, double, double, double);
_Bool init_file();


#endif

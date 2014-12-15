
/* ************************************************ */
/*                                                  */
/*   FILE: broyden_file.c                           */
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

#include <stdio.h>           // printf(), fprint(), fscan()

#include "broyden_file.h"
#include "broyden_input.h"
#include "broyden_output.h"  // for format string MATRIX_ENTRY

//---------------------------------------------------
//
//  Output-file management
//
//---------------------------------------------------


// OUTPUT
// prints into output-file:
// step | ||f(x_k)|| | ||x_k-x_(k-1)|| | rate of convergence
_Bool print_into_file(int i, double f_k, double e_k, double conv)
{
  // open file to write in
  FILE* file=fopen(OUTPUT_FILE, "a");
  if(!file){return 0;} // error while opening file?

  // actual writing
  fprintf(file, "%i"MATRIX_ENTRY MATRIX_ENTRY MATRIX_ENTRY"\n", i, f_k, e_k, conv);
  int err = fflush(file);                         // complete output and ...
  if(err) {perror(NULL); fclose(file); return 0;} // ... check on errors

  err = fclose(file);               // close file, and again and ...
  if(err) {perror(NULL); return 0;} // ... check on errors

  return 1;
}



// FILE INIT
_Bool init_file()
{
  // try to open file
  FILE* file=fopen(OUTPUT_FILE, "r");
  if(!file)  // if not existing ...
    {
      // create file to write in
      file=fopen(OUTPUT_FILE, "w+");
      if(!file){return 0;}

      printf("Created file %s\n", OUTPUT_FILE);
    }
  else{     // if already existing ...
    printf("\nOverwrite output file %s?\n", OUTPUT_FILE);
    char c=get_yesno();
    if(c=='y') // user wants to overwrite
      {
	// create file
	file=fopen(OUTPUT_FILE, "w");
	if(!file){return 0;}
      }
    else{      // quit if not
      return 0;
    }
  }

  // write first line
  fprintf(file,"\n");
  fclose(file); // close again

  return 1;
}


/* ************************************************ */
/*                                                  */
/*   FILE: file_management.h                        */
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

#include<stdio.h>
#include "broyden_file.h"
#include "broyden_input.h"

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
  FILE* file=fopen("broyden_method_output.txt", "a");
  if(!file){return 0;} // error while opening file?

  printf("printing...: k:%i, |f(x_k)|:%f, |x_(k+1)-x_k|:%f, conv:%f\n",i,f_k,e_k,conv);
  //printf("file position: %i",fseek(file, -1, SEEK_END));// go to end of file
  fprintf(file, "%i  %8lf  %8lf  %8lf\n", i, f_k, e_k, conv);
  int err = fflush(file); // complete output and ...
  if(err) {perror(NULL); fclose(file); return 0;} // ... check on errors

  err = fclose(file); // close file, and again ...
  if(err) {perror(NULL); return 0;} // ... check on errors

  return 1;
}


// LOOP NOT WORKING
/* // READ-OUT */
/* // from output-file */
/* _Bool print_file() */
/* { */
/*   // open file to write in */
/*   FILE* file=fopen("broyden_method_output.txt", "r"); */
/*   if(!file){return 0;} // error while opening file? */

/*   int i; double f_k, e_k, conv; */
/*   printf("\nContent of broyden_method_output.txt:\n"); */
/*   printf(" k   |  |f(x_k)|  | |x_k-x_(k-1)| | rate of convergence\n"); */

/*   fgetc(file); // jump over first newline */
/*   // print entries until reaching end of file (fscanf will return 0) */
/*   _Bool b=1; */
/*   while(b-1) */
/*     { */
/*       b=fscanf(file, "%i  %8lf  %8lf  %8lf\n", &i, &f_k, &e_k, &conv); */
/*   printf("%i  %i  |  %8lf  |  %8lf  |  %8lf\n",b, i,f_k,e_k,conv); */
/*     } */

/*   fclose(file); // close file */
  
/*   return 1; */
/* } */


_Bool init_file()
{
  FILE* file=fopen(OUTPUT_FILE, "r");
  if(!file)
    {
      // create file
      file=fopen(OUTPUT_FILE, "w+");
      if(!file){return 0;}

      printf("Created file %s\n", OUTPUT_FILE);
    }
  else{
    printf("Overwrite output file %s?\n", OUTPUT_FILE);
    char c=get_yesno();
    if(c=='y')
      {
	// create file
	file=fopen(OUTPUT_FILE, "w");
	if(!file){return 0;}
      }
    else{
      return 0;
    }
  }

  // write first line
  fprintf(file,"\n");
  fclose(file); // close again

  return 1;
}

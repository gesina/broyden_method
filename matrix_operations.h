#ifndef MATRIXOPERATIONS
#define MATRIXOPERATIONS

/* ************************************************ */
/*                                                  */
/*   FILE: matrix_operations.h                      */
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
//   Matrix math operations
//
//---------------------------------------------------


// MEMORY MANAGEMENT
// allocates memory for matrix
double** init_matrix(int m, int n);

// allocates memory for vector
double* init_vector(int);

// free memory from matrix
void free_memory_matrix(double**, int, int);

// free memory from vector
void free_memory_vector(void*);

// COPY FUNCTIONS
// copy matrix A into B
void copy_matrix(double**, double**,int, int);

// copy vector a into b
void copy_vector(double*, double*,int);

// MATRIX MATHS
// multiplication of matrices
// A mxn-matrix, B nxl-matrix
double** mult_matrix(double**, double**, int, int, int);

// addition of matrices
double** add_matrix(double**, double**, int, int);

// scalar product of vectors (l_2-norm)
double scprod_vector(double*, int);

#endif


/* ************************************************ */
/*                                                  */
/*   FILE: matrix_operations.c                      */
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

#include <stdio.h>             // printf, scanf
#include <stdlib.h>            // malloc
#include <math.h>              // pow, exp, sin

#include "matrix_operations.h"



// MEMORY MANAGEMENT
// allocates space for matrix in memory
 double** init_matrix(int m, int n)
{
  // allocate space for matrix row-pointer
  double** matrix = (double**) malloc(m*sizeof(double*));
  
  // got space in memory?
  if ( matrix == NULL )
    {
      printf("\nError allociating space in memory for the matrix!\n");
      printf("Problem occured with init of A\n");
      return NULL; // exit
    }

  // allocate space for matrix rows 
  for ( int i=0; i<m; i++)
    {
      // and for entries in rows
      matrix[i] = (double*) malloc(n*sizeof(double));

      // got space in memory?
      if(matrix[i] == NULL)
	{
	  printf("\nError allociating space in memory for the matrix!\n");
	  printf("Problem occured with row: A[%d]\n", i);
	  return NULL; // exit
	}
    }

  return matrix;  
};


// allocates memory for vector
double* init_vector(int dim)
{
  // allocate space for vector
  double* vector = (double*) malloc(dim*sizeof(double));
  
  // got space in memory?
  if ( vector == NULL )
    {
      printf("\nError allociating space in memory for the vector!\n");
      printf("Problem occured with init of vector.\n");
      return NULL; // exit
    }

  return vector;  
};



// memory free function for matrix
void free_memory_matrix(double** A, int m, int n)     // free memory from matrix
{
  // free rows
  for (int i=0; i<m; i++)
    {
      free(A[i]);
    }
  free(A);
}

// memory free function for vector
void free_memory_vector(void* x)                 // free memory from vector
{
    free(x);
}



// COPY FUNCTIONS
// copy function for matrices
void copy_matrix(double** A, double** B,int m, int n) // copy matrix A into B
{
  //printf("in copymatrix with A:%f, B:%f, m:%i, n:%i",**A,**B,m,n);
  // rows
  for (int i=0; i<m; i++)
    {
      //columns
      for ( int j=0; j<n; j++)
	{
	  B[i][j] = A[i][j];
	}
    };
}


// copy function for vectors  (copy vector a into b)
void copy_vector(double* a, double* b ,int dim)
{
  for (int i=0; i<dim; i++)
    {
      a[i] = b[i];
    }
}



// MATRIX MATHS
// multiplication of matrices
double** mult_matrix(double** A, double** B, int m, int n, int l)
//m Zeilen von A, n Spalten von A und Zeilen von B, l Spalten von B
{
  double** C=init_matrix(m, l);
  
  for(int i=0; i<m; i++) //Zeilen
    {
    for(int k=0; k<l; k++) //Spalten
      {
	for(int j=0; j<n; j++) 
	  {
	    C[i][k] += A[i][j] * B[j][k];
	  }
      }
    }
  
  return C;
}


// addition of matrices (returns A+B)
double** add_matrix(double** A, double** B, int m, int n)
{
  double** C=init_matrix(m, n);
  
  for(int i=0; i<m; i++)   // rows
  {
    for(int j=0; j<n; j++) // columns
      {
  	  C[i][j] = A[i][j] + B[i][j];
      }
  }

  return C;
}



// scalar product of vectors (l_2-norm)
double scprod_vector(double* x, int dim)
{
  double scprod=0;
  for(int i=0; i<dim; i++)
    {
      scprod += pow(x[i],2);
    }

  return scprod;
}


/* ************************************************ */
/*                                                  */
/*   FILE: includes.h                               */
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
//  Summary of all included files
//    and all needed predefinitions
//
//---------------------------------------------------



// extern libraries
#include<stdlib.h>     // malloc & free for matrix/vector init
#include<stdio.h>      // printf(), scanf()
#include<math.h>       // fabs(), exp(), sin(), pow()
#include<string.h>     // strchr()
// VARIABLES
static int dimension = -1; // -1: to test, whether get_dimension() worked
static double tolerance = -1; // -1: to test, whether get_tolerance() worked
// function ids:
/*  (1) linear(): 0.5*x
    (2) example_ii(): f(x) = {{(x1+3)(x2^2-7)+18},{sin(x2*exp(x1)-1}}
    (3) example_iii(): f(x) = {{x1+x2-3},{x1^2+x2^2-9}}
*/
#define FUNCTION_OPTIONS "123"
#define FUNCTION_OPTIONS_PRINT "\n  (1) f(x)=x-1\n \
 (2) f(x) = {{(x1+3)(x2^2-7)+18},{sin(x2*exp(x1)-1}}\n \
 (3) f(x) = {{x1+x2-3},{x1^2+x2^2-9}}\n"

// machine epsilon
#define DBL_EPSILON 2.2204460492503131E-16

// PRINT-FUNCTIONS
void print_init(); // greetings
void print_exit(); // bye bye

void print_matrix(double** A, int m, int n);
void print_vector(double* b, int dim);

// GET-FUNCTIONS
double get_tolerance(); // gets convergence tolerance
char get_function(); // gets wanted function to get zero of
void set_matrix(double** B, int m, int n); // gets+sets matrix entries from user
void set_vector(double* x, int dim); // gets+sets vector entries from user

// INIT-FUNCTIONS
double** init_matrix(int m,int n); // allocates memory for mxn-matrix
double* init_vector(int dim); // allocates memory for vector
void free_memory_matrix(double** A, int m, int n);  // free memory from matrix
void free_memory_vector(void* x);   // free memory from vector


// MATH-OPERATIONS
void copy_matrix(double** A,double** B,int m,int n); // copy mxn-matrix A into B
void copy_vector(double* a, double* b, int dim); // copy vector a into b

double** add_matrix(double** A, double** B, int m, int n); // add two mxn-matrices
double** mult_matrix(double** A, double** B,int m, int n, int l); // mult mxn-matrix A
                                                       // with nxl-matrix B

// LU DECOMPOSITION
int solve_equation(double** A, double* b,int dim, double* x); // solve Ax=b and
                                                               // write into x
int lu_decomposition(double** A, int* pi, int dim);
void forward_substitution(double* b, int* pi, double** L, int dim);   // b~>z
void backward_substitution(double** U, double* z, double* x, int dim);// solve Ux=z

// FUNCTIONS AND FUNCTION DESCRIPTIONS
#define LINEAR "LINEAR"
double* linear(double* arg);

#define EXAMPLE_II "f(x) = {{(x1+3)(x2^2-7)+18},{sin(x2*exp(x1)-1}}"
double* example_ii(double* arg);

#define EXAMPLE_III "f(x) = {{x1+x2-3},{x1^2+x2^2-9}}"
double* example_iii(double* arg);

// BROYDEN METHOD FUNCTIONS


// HOMEMADE LIBRARIES
#include "print.h"              // print & error functions
#include "input.h"              // init, free & copy functions 
#include "solve_equation.h"     // LU_decomposition for Ax=b
#include "math_operations.h"    // matrix math operations
#include "functions.h"          // function options
#include "broyden_method.h"     // Broyden's method

// ERROR CODES:
//  3: tolerance error, tolerance after user input lower 0
//  2: allociation error, malloc() didn't work
//  1: matrix not decomposable
//  0: exited normally

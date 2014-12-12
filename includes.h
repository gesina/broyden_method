
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

// struct for return data of broyden_method()
struct x_f_step_flag
{
  double* x;      // x_k for max. k
  double* f;      // f(x_k) 
  int step;       // k
  int flag;     // success indicator:
                  // (1) maximal iteration step input not enough
                  // (0) successful iteration within tolerance
};

#define OUTPUT_FILE "broyden_method_output.txt" // output for step results


// PRINT-FUNCTIONS
void print_init(); // greetings
void print_exit(); // bye bye

void print_matrix(double** A, int m, int n);
void print_vector(double* b, int dim);

// GET-FUNCTIONS
double get_tolerance(); // gets convergence tolerance
char get_function(); // gets wanted function to get zero of
int get_maxit(); // gets maximal number of iteration steps
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
#define LINEAR "f(x)=x-1\n"
void linear(double* arg, double* res);

#define EXAMPLE_II "f(x) = {{(x1+3)(x2^2-7)+18},{sin(x2*exp(x1)-1}}\n"
void example_ii(double* arg, double* res);
_Bool ex_ii_predef_x1(double** x, double*** B, double* tol, int* maxit);
_Bool ex_ii_predef_x2(double** x, double*** B, double* tol, int* maxit);

#define EXAMPLE_III "f(x) = {{x1+x2-3},{x1^2+x2^2-9}}\n"
void example_iii(double* arg, double* res);
_Bool ex_iii_predef_B1(double** x, double*** B, double* tol, int* maxit);
_Bool ex_iii_predef_B2(double** x, double*** B, double* tol, int* maxit);


// FILE MANAGEMENT
_Bool print_into_file(int i, double f_k, double e_k, double conv);
_Bool print_file();
_Bool init_file();

// BROYDEN METHOD FUNCTIONS
struct x_f_step_flag broyden_method(void (*function)(double*,double*), int dim, double* x, double** B, int maxit, double tol);
// return values: 

// HOMEMADE LIBRARIES
#include "broyden_print.h"              // print & error functions
#include "broyden_input.h"              // init, free & copy functions 
#include "math_operations.h"    // matrix math operations
#include "solve_equation.h"     // LU_decomposition for Ax=b
#include "broyden_functions.h"          // function options
#include "broyden_file.h"    // printing into and out from file
#include "broyden_method.h"     // Broyden's method

// ERROR CODES:
//  4: file error, opening/creation failed
//  3: tolerance error, tolerance after user input lower 0
//  2: allociation error, malloc() didn't work
//  1: matrix not decomposable
//  0: exited normally

/* ************************************************ */
/*                                                  */
/*   FILE: input.h                                  */
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
//    and memory allocation
//
//---------------------------------------------------


// GET-FUNCTIONS

char get_yesno()  // ask user for input of yes or no
{
  _Bool b=1;
  char c=' ';
  printf(" Please enter yes (y) or no (n):  ");
   do
    {
      // while(getchar()!='\n');  // necessary to avoid reading newline
      scanf("%c", &c);                             // get user input
      if ( c=='y' || c=='n' ) {b=0;}              // ok --> quit
      else if (c=='\n') {b=1;}                    // newline --> again
      else { printf("Please enter y or n :  "); }     // not ok --> repeat
    }
  while(b);

  return c; // return y or n
    
}


char get_function()  // ask user for input of yes or no
{
  _Bool b=1;
  char c=' ';
  printf("\nPlease enter one of the following%s:  ", FUNCTION_OPTIONS_PRINT);
  do
    {
      //while(getchar()!='\n');  // necessary to avoid reading newline
      scanf("%c", &c);                             // get user input
      // check, whether input is in FUNCTION_OPTIONS-string
      if ( strchr(FUNCTION_OPTIONS, c) != NULL ) {
	printf("You entered option %c. Take it?\n", c);
	if(get_yesno()=='y'){b=0;}
      }// input ok and wanted--> quit
      else if( c=='\n' ){b=1;}
      else {
	printf("Please enter only one of the following %s: ", FUNCTION_OPTIONS_PRINT);
      }// not ok --> repeat
      
    }
  while(b);
  return c; // return a function-id
}



double get_tolerance()  // gets the convergence tolerance
{

  double tol = -1; // tolerance to return
  _Bool b=0;     // test bool for while-loop

  printf("\nPlease enter the tolerance:  ");
  do  // as long as input doesn't make sense: repeat
    {
      b=0; // stop if not set to 1
      
      //while(getchar()!='\n');  // necessary to avoid reading newline
      scanf("%lf", &tol); // user read in
      // verify input
      if ( tol <= 0 )
	{
	  b=1;   // repeat if senseless ...
	  printf("\n  Please enter a tolerance greater than zero!\n");
	  printf("   Your input: %f\n", tol);
	  printf("Try again:  "); // ... and give some warning
	}
      else {
	printf("You entered for tolerance %f. Take it?\n", tol);
	if(get_yesno()!='y'){
	  printf("Then try again: ");
	  b=1;
	}
      }
    }
  while(b);

  return tol;

}


int get_maxit()  // gets maximum number of iteration steps
{

  int maxit = -1; // number of steps to return
  _Bool b=0;     // test bool for while-loop

  
  printf("\nPlease enter the maximum number of iteration steps:  ");
  do  // as long as input doesn't make sense: repeat
    {
      b=0; // stop if not set to 1
      scanf("%d", &maxit); // user read in

      // verify input
      if ( maxit <= 0 )
	{
	  b=1;   // repeat if senseless
	  printf("  Please enter a maximum number of iterations greater than zero!\n");
	  printf("   Your input: %i\n", maxit);
	  printf("Try again:  "); // and give some warning
	};

    }
  while(b);

  return maxit;
}

 
void set_matrix(double** A, int m, int n) // gets+sets matrix entries from user (A)
{
  
  _Bool b=0;     // test bool for while-loop
  char c=' ';     // helper character

  printf("\nDimension for set_matrix: %i x %i\n" , m, n);
  printf("Please enter the matrix entries separately.\n");
  do  // as long as input doesn't make sense: repeat
    {
      b=1; // stop default
      
      for (int i=0; i<m; i++)
	{
	  printf(" Enter row #%i:\n", i+1);

	  // read entries in
	  for ( int j=0; j<n; j++)
	    {
	      //while(getchar()!='\n');  // necessary to avoid reading newline
	      scanf("%lf", &A[i][j]); // user read in
	    }
	  
	  // show full row:
	  printf("Row #%i: ", i+1);
	  for (int k=0; k<n; k++)
	    {
	      printf(" | %f", &A[i][k]);
	    }
	}

      // ask, wether to continue or to try again  
      printf("\nYour entries have produced this matrix:\n");
      print_matrix(A, m,n);
      printf("Take these entries?\n");
      
      c = get_yesno();
      if ( c=='y' ) { b=0;}
      else {printf("\nTry again and enter the first row:\n");}
      
    }
  while(b);

}

void set_vector(double* b, int dim) // gets+sets vector entries from user (b)
{
  
  _Bool g=0;     // test bool for while-loop
  char c=' ';     // helper character

  printf("\nPlease enter the entries of the vector: \n");
  do  // as long as input doesn't make sense: repeat
    {
      
      g=1; // stop default
      
      // read entries in
      for ( int i=0; i<dim; i++)
	{
	  //while(getchar()!='\n');  // necessary to avoid reading newline
	  scanf("%lf", &b[i]); // user read in
	}
	 
      // ask, wether to continue or to try again  
      printf("\nYour entries have produced this vector:\n");
      print_vector(b, dim);
      printf("Take these entries?");
      
      c = get_yesno();
      if ( c=='y' ) { g=0;}
      else {printf("\nTry again and enter the vector:\n");}
      
    }
  while(g);

}



// MEMORY MANAGEMENT

// allocation functions
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


double* init_vector(int dim) // allocates memory for vector
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



// memory free functions
void free_memory_matrix(double** A, int m, int n)     // free memory from matrix
{
  // free rows
  for (int i=0; i<m; i++)
    {
      free(A[i]);
    }
  free(A);
}


void free_memory_vector(void* x)                 // free memory from vector
{
    free(x);
}




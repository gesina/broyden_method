
/* ************************************************ */
/*                                                  */
/*   FILE: solve_equation.h                         */
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
//  LU decomposition to solve Ax=b
//
//---------------------------------------------------


// LU DECOMPOSITION
// of given Matrix A, returns completion indicator
int lu_decomposition(double** A, int* pi, int dim)
{
  // write pi
  //for (int i=0; i<dim; i++){ *(pi+i) = i;}

  double max_entry=0, next_entry=0;
  int temp_pi=0;
  double* temp_a=0;
  
  for (int k=0; k<dim-1; k++)
    {
      // Pivoting
      //---------------------------------
      // find maximum absolute value of entries
      max_entry= fabs(*(*(A+k)+k));      // set max to abs. value
                                         // of entry #k in row #k
      int pos_max_entry=k;
      
      for (int i=k+1; i<dim; i++)
	{
	  next_entry=fabs(*(*(A+i)+k));  // get next abs. entry
	  
	  if(max_entry < next_entry)     // and if greater ...
	    {
	      max_entry = next_entry;    // ... take it as max
	      pos_max_entry = i;
	    }
	}

      // swap rows
      temp_pi = pi[k];                       // in pi
      pi[k]=pi[pos_max_entry];
      pi[pos_max_entry]=temp_pi; 

      temp_a = *(A+k);                       // in A
      *(A+k)=*(A+pos_max_entry);
      *(A+pos_max_entry)=temp_a;

      // print step
      printf("\n\n STEP %d\n", k+1);
      printf("*******************");
      // print current Pivot index
      printf("\nCurrent Pivot index:  A[%d][%d] = %f", pos_max_entry, k, (*(*A+k)+k));
      printf("\n Matrix:\n");
      print_matrix(A, dim);
      printf("\n Permutation vector:\n");
      // print pi
      for(int i=0; i<dim; i++)
	{
	  printf("   %d \n", *(pi+i));
	}



      
      // LU Decomposition
      //---------------------------------
      // check, whether next step executable:
      if ( max_entry == 0 )
	{
	  err_not_executable(k+1);
	  return k+1;
	}

      // change entries
      for (int i=k+1; i<dim; i++)
	{
	  // L
	  // l_{ik} = a_{ik}/a_{kk}
	  *(*(A+i)+k) = (*(*(A+i)+k))/ (*(*(A+k)+k));
	  for (int j=k+1; j<dim; j++)
	    {
	      // R
	      // a_{ij} = a_{ij} - l_{ik}*a_{ki}
	      *(*(A+i)+j) = *(*(A+i)+j) - ( (*(*(A+i)+k)) * (*(*(A+k)+j)) );
	    }
	}

      // print result of this step
      printf("\n New Matrix:\n");
      print_matrix(A, dim);
      
    }


  // last check on singularity:
  if ( fabs(*(*(A+dim-1)+dim-1)) <= DBL_EPSILON ) // last pivot element zero?
    {
      printf("\n\nRESULT of LU DECOMPOSITION:\n");
      printf("************************************************************\n");
      printf("\nThe LU decomposition of A results in\n");
      print_matrix(A, dim);
      printf("\nBut A is not regular!!");
      printf("\nThus there's not always a solution for Ax=b independently of b,");
      printf("\n  and we cannot proceed, sorry.\n\n");
      
      return dim;  // return last step failed
    }
  

  return 0; // finished and worked well
}





// FORWARD SUBSTITUTION
// changes given vector b to z
void forward_substitution(double* b_in, int* pi, double** L, int dim)
{
  double temp_b=0; // for swaping of row entries
  double* b = copy_matrix
  
  // first swap all rows into new order
  for (int k=0; k<dim-1; k++)
    {
      // swap rows  b[k]<~>b[pi[k]]
      temp_b = b[k];
      b[k] = b[pi[k]];
      b[pi[k]] = temp_b;
    }

  // now calculate new entries iteratively
  for (int k=0; k<dim-1; k++)
    {
      // forward substitution
      for (int i=k+1; i<dim; i++)
	{
	  // b_{i} = b_{i} - l_{ik}*b_{k}
	  *(b+i) = *(b+i) - ( (*(*(L+i)+k)) * (*(b+k)) );
	}
    }


  // print result
  printf("\n Vector after forward substitution:\n");
  print_vector(b, dim);
  
}



// BACKWARD SUBSTITUTION
// writes solution of Ux=z into given vector x
void backward_substitution(double** U, double* z, double* x, int dim)
{
  // go through the entries in x and set
  // x_{k} = [ z_{k}^{(k-1)} - ( \sum_{j=k+1}^{n} r_{kj}^{(k-1)}*x_{j} ) ]
  
  // for k=n, ..., 1
  for (int k=dim-1; k>=0; k--)
    {
      // x_{k} = z_{k}
      *(x+k) = *(z+k);

      // for j=k+1, ..., n
      for (int j=k+1; j<dim; j++)
	{
	  // x_{k} = x_{k}-r_{kj}x_{j}
	  *(x+k) = *(x+k) - (*(*(U+k)+j)) * (*(x+j));
	}

      // x_{k} = x_{k}/r_{kk}
      *(x+k) = (*(x+k)) /  (*(*(U+k)+k));
    }
}






// prepares call of lu_decomposition
//   (init of LU, pi)
// and returns struct with LU, pi, step
int solve_equation(double** A, double* b, int dimension, double* x)
{
  // init of struct to return
  // with default value for allociation error
  struct LU_pi_step return_struct = {NULL, NULL, -1};
  
  // init of permutation vector pi
  int* pi= (int*) malloc(dimension*sizeof(int));
  if ( pi == NULL )   // error with allociation?
    {
      printf("Error allociating space in memory for the vector!\n");
      printf("Problem occured with init of permutation vector.");
      return -1;  // return: allociation error
    };
  
  // write entries of permutation vector
  for (int i=0; i<dimension; i++){ *(return_struct.pi+i) = i;}


  // init of LU matrix
  double** LU = init_matrix(dimension);
  if (!return_struct.LU)            // error with allociation?
    {
      return -1;  // return: allociation error
    }
  
  // set return_struct.LU to A:
  copy_matrix(A, LU, dimension);

  
  // decompose A to LU and set step as success indicator
  // (step=0: worked well;
  //  step>0: failed on step number step)
  int step=lu_decomposition(LU, return_struct.pi, dimension);
  if( step>0 ) // worked?
    {
      printf("LU decomposition failed at step %d", step);
      return -1;
    }

  // forward substitution: b~>z
  forward_substitution(b, pi, LU, dimension);
  
  
  return return_struct;  // return LU, pi, step
  
}




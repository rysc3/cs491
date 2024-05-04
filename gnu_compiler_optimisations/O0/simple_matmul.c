#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void matmul( int r1, int c1, int r2, int c2 )
{
  // Indicies
  int i, j, k;
  
  // Allocate memory to store A, B, and resulting matrix C
  double(*A)[r1][c1] = malloc(sizeof *A);
  double(*B)[r2][c2] = malloc(sizeof *B);
  double(*C)[r1][c2] = malloc(sizeof *C);
  
  // Fill operands with random numbers
  for (i = 0; i < r1; ++i)
    for (j = 0; j < c1; ++j)
      (*A)[i][j] = rand() /RAND_MAX;
  
  for (i = 0; i < r2; ++i)
    for (j = 0; j < c2; ++j)
      (*B)[i][j] = rand()/ RAND_MAX;
          
  // Initialize all elements of result matrix C to 0
  for (i = 0; i < r1; ++i)   
    for (j = 0; j < c2; ++j)
      (*C)[i][j] = 0;
  
  clock_t begin1 = clock();
  
  // Multiplying matrices A and B and
  // storing result in C
  for (i = 0; i < r1; ++i)
    for (j = 0; j < c2; ++j)
      for (k = 0; k < c1; ++k)
	(*C)[i][j] += (*A)[i][k] * (*B)[k][j];

  clock_t end1 = clock();
  
  double time_taken = (double)(end1 - begin1) / CLOCKS_PER_SEC;
  printf("\n %dx%d * %dx%d took %f seconds\n", r1, c1, r2, c2, time_taken);
  
  // Clean up matricies
  free(A);
  free(B);
  free(C);
}

int main( int argc, char** argv )
{
  // Check usage
  if ( argc != 5 )
    {
      printf("Usage: %s {Arows} {Acols} {Brows} {Bcols}\n", argv[0]);
      return 1;
    }
  
  // Execute matmul and print time
  int r1 = atoi(argv[1]);
  int c1 = atoi(argv[2]);
  int r2 = atoi(argv[3]);
  int c2 = atoi(argv[4]);

  // Check dimensions
  if ( c1 != r2)
    {
      printf("Acols must equal Brows\n");
      return 2;
   }
  
  matmul(r1, c1, r2, c2);
  
  return 0;
}

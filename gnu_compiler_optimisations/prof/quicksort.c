// Quicksort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// main function
int main( int argc, char** argv )
{ 
  // Check usage
  if ( argc != 2 )
    {
      printf("Usage: %s {array size}\n", argv[0]);
      return 1;
    }

  int array_size = atoi( argv[1] );

  // Check input size. Atoi returns 0 if it doesn't understand the input string. Zero is also invalid as a size.
  if (array_size == 0)
    {
      printf("Usage: %s {array size}\n", argv[0]);
      printf("%s is an invalid array size.", argv[1]);
      return 2;
    }

  // We want to time sorting of very large arrays. The heap has a lot more space than stack memory so
  // allocate the array there with malloc. *array is a pointer to the beginning of the memory we allocate.
  int* array = (int*) malloc(array_size * sizeof(int));

  // Check if we got the memory
  if (array == NULL) {
    printf("Memory allocation failed!");
    return 3;
  }

  // Use the time to choose a seed for the random number generator so we get differnt numbers each run
  srand(time(0));
  for(int i=0; i< array_size; i++)
    array[i]=rand();   //Generate number between 0 and RAND_MAX

  // If compiled with debug defined, print the array
  // E.g. gcc quicksort.c -DDEBUG -o gnu_quicksort
  #ifdef DEBUG
  printf("Unsorted Array\n");
  printArray(array, array_size);
  #endif
  
  // perform quicksort on data
  clock_t begin = clock();
  quickSort(array, 0, array_size - 1);
  clock_t end = clock();

  double time_taken = (double)(end - begin) / CLOCKS_PER_SEC;

  // Working with large array sizes so print the size in scientific format
  printf("Sorting %.e elements took %f seconds\n", (double)array_size, time_taken);
  
  // If compiled with debug defined, print the array
  // E.g. gcc quicksort.c -DDEBUG -o gnu_quicksort
  #ifdef DEBUG
  printf("Sorted array in ascending order: \n");
  printArray(array, array_size);
  #endif

  // Apparent success so free the memory used to store the array and return 0
  free(array);    
  return 0;
}

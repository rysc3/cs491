#include "timing.h"
#include "add.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE (1024 * 1024)

static unsigned short A[MAX_SIZE];
static unsigned short B[MAX_SIZE];

void all_for_function(const char *name, function_type func) {
    // NB: There is no code to verify functions are correct here.
    printf("%-10s Cycles/Element for %s\n", "Size", name);
    for (int i = 16; i <= MAX_SIZE; i *= 2) {
        cycles_type t = measure_function(i, (generic_function_type) func, A, B);
        printf("%-10d %7.2f\n", i, (double) t / (double) i);
    }
    printf("\n");
}

int main(void) {
  
    srand(42);
    for (int i = 0; i < MAX_SIZE; ++i) {
        A[i] = rand() % 10000;
        B[i] = rand() % 10000;
    }

    __builtin_cpu_init();
    for (int i = 0; functions[i].name != NULL; ++i) {
      printf("%s\n", functions[i].name);
      
      if ( strcmp( functions[i].name, "Scalar") == 0 )
	all_for_function(functions[i].name, functions[i].f);
      else if ( strcmp( functions[i].name, "SSE") == 0 ) {
	if ( __builtin_cpu_supports( "sse" ) ) {
	  printf("Support for %s detected. Adding %s benchmarks. \n", functions[i].name, functions[i].name );
	  all_for_function(functions[i].name, functions[i].f); }
	else
	  printf("Support for %s not detected. Skipping %s benchmarks. \n", functions[i].name, functions[i].name );
      }
      else if (strcmp( functions[i].name, "AVX" ) == 0 ) {
	if ( __builtin_cpu_supports( "avx" ) ) {
	  printf("Support for %s detected. Adding %s benchmarks. \n", functions[i].name, functions[i].name );
	  all_for_function(functions[i].name, functions[i].f);
	}
	else
	  printf("Support for %s not detected. Skipping %s benchmarks. \n", functions[i].name, functions[i].name );
      }      
      else if ( strcmp( functions[i].name, "AVX2") == 0 ) {
	if ( __builtin_cpu_supports( "avx2" ) ) {
	  printf("Support for %s detected. Adding%s benchmarks. \n", functions[i].name, functions[i].name );
	  all_for_function(functions[i].name, functions[i].f);
	}
	else
	  printf("Support for %s not detected. Skipping %s benchmarks. \n", functions[i].name, functions[i].name );
      }
    }
}


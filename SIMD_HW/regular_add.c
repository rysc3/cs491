/* header file for Intel intrinsics */
#include <immintrin.h>
#include <smmintrin.h>

#define MAX_SIZE (1024 * 1024)

static unsigned short A[MAX_SIZE];
static unsigned short B[MAX_SIZE];


/* reference implementation in C */
void add(long size, unsigned short * a, const unsigned short *b) {
    for (int i = 0; i < size; ++i) {
        a[i] += b[i];
    }
}

int main()
{
  for (int i = 0; i < 10e3; i++ )
    add(MAX_SIZE, A, B);

  return 0;
}

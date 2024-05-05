/* header file for Intel intrinsics */
#include <immintrin.h>
#include <smmintrin.h>

#define MAX_SIZE (1024 * 1024)

static unsigned short A[MAX_SIZE];
static unsigned short B[MAX_SIZE];

/* vectorized version --- 128-bit regiters */
void add_SSE(long size, unsigned short * a, const unsigned short *b) {
    for (int i = 0; i < size; i += 8) {
        /* load 128 bits from a */
        /* a_part = {a[i], a[i+1], a[i+2], ..., a[i+7]} */
        __m128i a_part = _mm_loadu_si128((__m128i*) &a[i]);
        /* load 128 bits from b */
        /* b_part = {b[i], b[i+1], b[i+2], ..., b[i+7]} */
        __m128i b_part = _mm_loadu_si128((__m128i*) &b[i]);
        /* a_part = {a[i] + b[i], a[i+1] + b[i+1], ...,                                                    
                     a[i+7] + b[i+7]}                                                                      
         */
        a_part = _mm_add_epi16(a_part, b_part);
        _mm_storeu_si128((__m128i*) &a[i], a_part);
    }
}

int main()
{
  for (int i = 0; i < 10e3; i++ )
    add_SSE(MAX_SIZE, A, B);

  return 0;
}

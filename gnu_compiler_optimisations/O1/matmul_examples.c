#if defined(SLOWEST)
    void multiply (float **A, float **B, float **out, int size) {
        for (int row=0;row<size;row++)
            for (int col=0;col<size;col++)
                for (int in=0;in<size;in++)
                    out[row][col] += A[row][in] * B[in][col];
    }
// Takes in 1-D arrays, same as before.
#elif defined(SLOWER)
    void multiply (float *A, float *B, float *out, int size) {
        for (int row=0;row<size;row++)
            for (int col=0;col<size;col++)
                for (int in=0;in<size;in++)
                    out[row * size + col] += A[row * size + in] * B[in * size + col];
    }
// Flips first and second loops
#elif defined(SLOW)
    void multiply (float *A, float *B, float *out, int size) {
        for (int col=0;col<size;col++)
            for (int row=0;row<size;row++) {
                float curr = 0;  // prevents from calculating position each time through
                for (int in=0;in<size;in++)
                    curr += A[row * size + in] * B[in *size + col];
                out[row * size + col] = curr;
            }
    }
#elif defined(MEDIUM)
    // Keeps it organized for future codes.
    float dotProduct(float *A, float *B, int size) {
        float curr = 0;

        for (int i=0;i<size;i++)
            curr += A[i] * B[i];

        return curr;
    }
    void multiply (float *A, float *B, float *out, int size) {
        float *temp = new float[size];

        for (int col=0;col<size;col++) {
            for (int i=0;i<size;i++)  // stores column into sequential array
                temp[i] = B[i * size + col];
            for (int row=0;row<size;row++)
                out[row * size + col] = dotProduct(&A[row], temp, size);  // uses function above for dot product.
        }

        delete[] temp;
    }
#elif defined(MEDIUMISH)
    float dotProduct(float *A, float *B, int size) {
        float curr = 0;

        for (int i=0;i<size;i++)
            curr += A[i] * B[i];

        return curr;
    }
    void multiply (float *A, float *B, float *out, int size) {
        for (int i=0;i<size-1;i++)
            for (int j=i+1;j<size;j++)
                std::swap(B[i * size + j], B[j * size + i]);

        for (int col=0;col<size;col++)
            for (int row=0;row<size;row++)
                out[row * size + col] = dotProduct(&A[row], &B[row], size);  // uses function above for dot product.
    }
#elif defined(FAST)

#elif defined(FASTER)

#endif

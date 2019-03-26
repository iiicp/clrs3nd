#include <stdio.h>

#define LEN 2

void dispaly(int m[LEN][LEN]);
void square_matrix_multiply(int A[LEN][LEN], int B[LEN][LEN], int C[LEN][LEN], int len);

//straness 7 + 18
//pure  8 + 4

int main(int argc, const char * argv[]) {

    int A[LEN][LEN] = {{1, 3}, {7, 5}};
    int B[LEN][LEN] = {{6, 8}, {4, 2}};
    int C[LEN][LEN] = {0};
    
    dispaly(A);
    dispaly(B);
    square_matrix_multiply(A, B, C, LEN);
    dispaly(C);
    
    return 0;
}

// C[i][j] = A[i][k] * B[k][j]
void square_matrix_multiply(int A[LEN][LEN], int B[LEN][LEN], int C[LEN][LEN], int len) {
    
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < len; ++k) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

void dispaly(int m[LEN][LEN]) {
    for (int i = 0; i < LEN; ++i) {
        for (int j = 0; j < LEN; ++j) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

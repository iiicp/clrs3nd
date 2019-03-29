#include <stdio.h>
#include <stdlib.h>

void display(int *A, int len);
void counting_sort(int *A, int *B, int k, int len);

int main(int argc, const char * argv[]) {
    
    int a[8] = {2, 5, 3, 0, 2, 3, 0, 3};
    int b[8] = {0};
    
    display(a, 8);
    counting_sort(a, b, 6, 8);
    display(b, 8);
    
    return 0;
}

void counting_sort(int *A, int *B, int k, int len) {
    int *C = (int *)malloc(sizeof(float) * k);
    
    for (int i = 0; i < k; ++i) {
        C[i] = 0;
    }
    
    // count
    for (int i = 0; i < len; ++i) {
        C[A[i]]++;
    }
    
    // count index
    for (int i = 1; i < k; ++i) {
        C[i] = C[i] + C[i-1];
    }
    
    for (int i = len - 1; i >= 0; --i) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
    
    free(C);
}

void display(int *A, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

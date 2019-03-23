#include <stdio.h>
#include <stdlib.h>

//[0, len)
void display(int *A, int len);
//[p,q) [q,r)
void merge(int *A, int p, int q, int r);
//[p,r)
void merge_sort(int *A, int p, int r);


int main(void) {
    
    int a[30] = {
                    23, 22, 21, 19, 20,
                    15, 14, 17, 18, 13,
                    12, 79, 81, 27, 29,
                    33, 44, 10, 17, 15,
                    22, 33, 43, 26, 80,
                    27, 25, 22, 89, 33
                 };
    display(a, 30);
    merge_sort(a, 0, 30);
    display(a, 30);

    return 0;
}

void merge(int *A, int p, int q, int r) {

    int n1 = q - p;
    int n2 = r - q;

    int *L = (int *)malloc(sizeof(int) * n1);
    int *R = (int *)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = A[p+i];
    }

    for (int j = 0; j < n2; ++j) {
        R[j] = A[q+j];
    }

    int i = 0, j = 0;
    
    for (int k = p; k < r; ++k) {
        if (i < n1 && j < n2) {
           if (L[i] <= R[j]) {
                A[k] = L[i];
                ++i;
            }else {
                A[k] = R[j];
                ++j;
            }
        }else if (i == n1 && j < n2) {
            A[k] = R[j];
            ++j;
        }else if (j == n2 && i < n1) {
            A[k] = L[i];
            ++i;
        }
    }
    free(L);
    free(R);
}


void merge_sort(int *A, int p, int r) {
    if (r-p == 1) return;

    int q = p + (r - p)/2;
    merge_sort(A, p, q);
    merge_sort(A, q, r);
    merge(A, p, q, r);
}

void display(int *a, int len) {
    for (int i = 0; i < len; ++i) {
        if (i % 5 == 0)
            printf("\n");
        printf("%d ", a[i]);
    }
    printf("\n");
}

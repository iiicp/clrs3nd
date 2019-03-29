#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int min;
    int max;
}TwoTuple;

void display(int *A, int len);
TwoTuple find_min_max_value(int *A, int len);

void swap(int *A, int a, int b);
int partition(int *A, int p, int r);
int randomized_partition(int *A, int p, int r);
int randomized_select(int *A, int p, int r, int i);

int main(int argc, const char * argv[]) {
    
    int A[10] = {2,3,54,9,57,2,3,1,0,8};
    display(A, 10);
    TwoTuple t = find_min_max_value(A, 10);
    printf("min : %d, max : %d\n", t.min, t.max);
    
    int r[10] = {9,3,5,0,1,10,11,4,15,2};
    display(r, 10);
    int i = 9;
    int res = randomized_select(r, 0, 10, i);
    printf("find rank %d is: %d\n", i, res);
    
    return 0;
}

int partition(int *A, int p, int r) {
    int x = A[r-1];
    int i = p - 1, j = p;
    while (j < r - 1) {
        if (A[j] <= x) {
            i++;
            swap(A, i, j);
            j++;
        }else {
            j++;
        }
    }
    swap(A, i+1, j);
    
    return i+1;
}

int randomized_partition(int *A, int p, int r) {
    srand((unsigned)time(NULL));
    int i = rand() % (r - p);
    if (i != r - 1) {
        swap(A, i, r-1);
    }
    return partition(A, p, r);
}

//[p, r)
//assume number is inequality and p <= i < r
int randomized_select(int *A, int p, int r, int i) {
    if (r - p == 1) {
        return A[p];
    }
    int k = randomized_partition(A, p, r);
    if (k == i) {
        return A[k];
    }else if (k < i) {
        return randomized_select(A, k + 1, r, i);
    }else {
        return randomized_select(A, p, k, i);
    }
}

void swap(int *A, int a, int b) {
    int t = A[a];
    A[a] = A[b];
    A[b] = t;
}

TwoTuple find_min_max_value(int *A, int len) {
    
    if (len < 1) {
        TwoTuple t = {.min = 0, .max = 0};
        return t;
    }
    
    if (len == 1) {
        TwoTuple t = {.min = A[0], .max = A[0]};
        return t;
    }
    
    if (len == 2) {
        TwoTuple t = {.min = A[0], .max = A[1]};
        return t;
    }
    
    int min, max;
    
    if (len % 2 == 0) {
        if (A[0] < A[1]) {
            min = A[0];
            max = A[1];
        }else {
            min = A[1];
            max = A[0];
        }
        int i = 2;
        while (i < len-1) {
            if (A[i] < A[i+1]) {
                if (min > A[i]) {
                    min = A[i];
                }
                if (max < A[i+1]) {
                    max = A[i+1];
                }
            }else {
                if (min > A[i+1]) {
                    min = A[i+1];
                }
                if (max < A[i]) {
                    max = A[i];
                }
            }
            i++;
        }
    }else {
        min = A[0];
        max = A[0];
        int i = 1;
        while (i < len-1) {
            if (A[i] < A[i+1]) {
                if (min > A[i]) {
                    min = A[i];
                }
                if (max < A[i+1]) {
                    max = A[i+1];
                }
            }else {
                if (min > A[i+1]) {
                    min = A[i+1];
                }
                if (max < A[i]) {
                    max = A[i];
                }
            }
            i++;
        }
    }
    
    TwoTuple t = {.min = min, .max = max};
    return t;
}

void display(int *A, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

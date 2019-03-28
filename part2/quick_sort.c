#include <stdio.h>

typedef struct  {
    int l;
    int h;
}TwoTuple;

void display(int *A, int len);
void swap(int *A, int a, int b);
int partition(int *A, int p, int r);
void quick_sort(int *A, int p, int r);

TwoTuple partition_new(int *A, int p, int r);
void quick_sort_new(int *A, int p, int r);

int main(int argc, const char * argv[]) {
    
    int a[8] = {2,8,7,1,3,5,6,4};
    int b[8] = {2,5,3,2,2,2,2,2};
    int len = sizeof(a)/sizeof(a[0]);
    
    printf("A: \n");
    display(a, len);
    quick_sort(a, 0, len);
    display(a, len);
    
    printf("B: \n");
    display(b, len);
    quick_sort_new(b, 0, len);
    display(b, len);
    
    return 0;
}
// 分成两个数组可能为空
void quick_sort(int *A, int p, int r) {
    if (p >= r)
        return;
    int q = partition(A, p, r);
    quick_sort(A, p, q);
    quick_sort(A, q+1, r);
}

// [p, r)
int partition(int *A, int p, int r) {
    int x = A[r-1];
    int i = p - 1;
    for (int j = p; j < r - 1; ++j) {
        if (A[j] <= x) {
            i++;
            swap(A, i, j);
        }
    }
    swap(A, i+1, r-1);
    return i+1;
}

// [p, r)
// [p, i) < x  [i, h] == x  [h+1, r) > x
TwoTuple partition_new(int *A, int p, int r) {
    int x = A[p];
    int i = p, h = p;
    for (int j = p + 1; j < r; ++j) {
        if (A[j] < x) {
            h++;
            int t = A[j];
            A[j] = A[h];
            A[h] = A[i];
            A[i] = t;
            i++;
        }else if (A[j] == x) {
            h++;
            swap(A, h, j);
        }
    }
    TwoTuple t = {.l = i, .h = h};
    return t;
}

void quick_sort_new(int *A, int p, int r) {
    if (p >= r) {
        return;
    }
    TwoTuple t = partition_new(A, p, r);
    quick_sort_new(A, p, t.l);
    quick_sort_new(A, t.h + 1, r);
}

void swap(int *A, int a, int b) {
    int t = A[a];
    A[a] = A[b];
    A[b] = t;
}

void display(int *A, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

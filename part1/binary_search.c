#include <stdio.h>

int binary_search(int *A, int n, int key);
int binary_search_first_equal(int *A, int n, int key);
int binary_search_first_equal_or_larger(int *A, int n, int key);
int binary_search_first_larger(int *A, int n, int key);
int binary_search_last_equal(int *A, int n, int key);
int binary_search_last_equal_or_smaller(int *A, int n, int key);
int binary_search_last_smaller(int *A, int n, int key);

int main(int argc, const char * argv[]) {
    
    int a[10] = {0, 1, 2, 2, 2, 2, 3, 3, 3, 4};
   
    printf("arr: ");
    for(int i = 0;i < 10; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    printf("find number 3\n\n");

    int normal = binary_search(a, 10, 3);
    printf("normal : %d\n", normal);
    
    int first_equal = binary_search_first_equal(a, 10, 3);
    printf("first_equal : %d\n", first_equal);
    
    int first_equal_or_larger = binary_search_first_equal_or_larger(a, 10, 3);
    printf("first_equal_or_larger : %d\n", first_equal_or_larger);
    
    int first_larger = binary_search_first_larger(a, 10, 3);
    printf("first_larger : %d\n", first_larger);
    
    int last_equal = binary_search_last_equal(a, 10, 3);
    printf("last_equal : %d\n", last_equal);
    
    int last_equal_or_smaller = binary_search_last_equal_or_smaller(a, 10, 3);
    printf("last_eqaul_or_smaller: %d\n", last_equal_or_smaller);
    
    int last_smaller = binary_search_last_smaller(a, 10, 3);
    printf("last_smaller: %d\n", last_smaller);
    
    return 0;
}

int binary_search(int *A, int n, int key) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (key == A[mid]) {
            return mid;
        }else if (key > A[mid]) {
            left = mid + 1;
        }else if (key < A[mid]) {
            right = mid - 1;
        }
    }
    return -1;
}

int binary_search_first_equal(int *A, int n, int key) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (key <= A[mid]) {
            right = mid - 1;
        }else {
            left = mid + 1;
        }
    }
    
    if (left < n && A[left] == key) {
        return left;
    }
    return -1;
}

int binary_search_first_equal_or_larger(int *A, int n, int key) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (key <= A[mid]) {
            right = mid - 1;
        }else {
            left = mid + 1;
        }
    }
    return left;
}

int binary_search_first_larger(int *A, int n, int key) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (key < A[mid]) {
            right = mid - 1;
        }else {
            left = mid + 1;
        }
    }
    return left;
}

int binary_search_last_equal(int *A, int n, int key) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (key >= A[mid]) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    
    if (right < n && A[right] == key) {
        return right;
    }
    return -1;
}


int binary_search_last_equal_or_smaller(int *A, int n, int key) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (key >= A[mid]) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return right;
}

int binary_search_last_smaller(int *A, int n, int key) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (key > A[mid]) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return right;
}

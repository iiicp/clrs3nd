#include <stdio.h>
#include <stdlib.h>

void display(int *A, int len);
int  index_value_of_number(int num, int index);
void radix_sort(int *A, int len);

int main(int argc, const char * argv[]) {
    
    int r[9] = {53, 3, 542, 748, 14, 214, 154, 63, 616};
    display(r, 9);
    radix_sort(r, 9);
    display(r, 9);
    
    return 0;
}

int index_value_of_number(int num, int index) {
    int cnt = 0, d = 0;
    while (1) {
        d = num % 10;
        num = num / 10;
        if (num == 0 || cnt == index) {
            break;
        }
        cnt++;
    }
    if (cnt < index) {
        return 0;
    }else {
        return d;
    }
}

void radix_sort(int *A, int len) {
    int *buckets[10];
    for (int i = 0; i < 10; ++i) {
        buckets[i] = (int *)malloc(sizeof(int) * (len + 1));
        buckets[i][0] = 0;
    }
    
    for (int i = 0; i < 32; ++i) {
        
        for (int j = 0; j < len; ++j) {
            int digit = index_value_of_number(A[j], i);
            buckets[digit][0]++;
            buckets[digit][buckets[digit][0]] = A[j];
        }
        
        int l = 0;
        for (int k = 0; k < 10; ++k) {
            for (int j = 1; j <= buckets[k][0]; ++j) {
                A[l++] = buckets[k][j];
            }
            buckets[k][0] = 0;
        }
    }
    
    for (int i = 0; i < 10; ++i) {
        free(buckets[i]);
    }
}

void display(int *A, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

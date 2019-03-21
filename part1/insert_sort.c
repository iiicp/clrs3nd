#include <stdio.h>

void insert_sort(int *a, int len);
void display(int *a, int len);

int main(int argc, const char * argv[]) {

    int a[10] = {23,3,-4,23,222,3, 89, 74,44,0};
    
    display(a, 10);
    
    insert_sort(a, 10);
    
    display(a, 10);
    
    return 0;
}

void insert_sort(int *a, int len) {
    if (len <= 1) {
        return;
    }
    for (int i = 1; i < len; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void display(int *a, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>

#define LEFT(i)  (2 * (i) + 1)
#define RIGHT(i) (2 * (i) + 2)
#define PARENT(i) ((i) % 2 == 0) ? ((i)/2-1) : ((i)/2)

void display(int *A, int size);
void swap(int *A, int a, int b);
void max_heapify_recurrent(int *A, int i, int heap_size);
void max_heapify(int *A, int i, int heap_size);
void build_max_heap(int *A, int heap_size);
void heap_sort(int *A, int heap_size);

// priority queue
#define PQSIZE 20
typedef struct {
    int data[PQSIZE];
    int index;
    int capacity;
}PQ;

PQ * pq_init(void);
int  pq_maximum(PQ *A);
int  pq_extract_max(PQ *A);
int  pq_increase_key(PQ *A, int i, int key);
void pq_insert(PQ *A, int key);
void pq_release(PQ *A);

int main(int argc, const char * argv[]) {
    
    int a[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    
    display(a, 10);
    heap_sort(a, 10);
    display(a, 10);
    
    return 0;
}

void display(int *A, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int *A, int a, int b) {
    int t = A[a];
    A[a] = A[b];
    A[b] = t;
}

// O(lgn)
void max_heapify_recurrent(int *A, int i, int heap_size) {
    
    int l = LEFT(i), r = RIGHT(i);
    
    int largest = i;
    
    if (l < heap_size && A[l] > A[i]) {
        largest = l;
    }
    
    if (r < heap_size && A[r] > A[largest]) {
        largest = r;
    }
    
    if (largest != i) {
        swap(A, i, largest);
        max_heapify_recurrent(A, largest, heap_size);
    }
}

void max_heapify(int *A, int i, int heap_size) {
    int largest = i;
    int l, r;
    
    do {
        i = largest;
        l = LEFT(i);
        r = RIGHT(i);
        
        if (l < heap_size && A[l] > A[i]) {
            largest = l;
        }
        
        if (r < heap_size && A[r] > A[largest]) {
            largest = r;
        }
        
        if (i != largest) {
            swap(A, i, largest);
        }
      
    } while (i != largest);
}

void build_max_heap(int *A, int heap_size) {
    for (int i = heap_size/2; i >= 0; --i) {
        max_heapify(A, i, heap_size);
    }
}

void heap_sort(int *A, int heap_size) {
    build_max_heap(A, heap_size);
    
    for (int i = heap_size - 1; i > 0; --i) {
        swap(A, 0, i);
        max_heapify(A, 0, i);
    }
}

PQ * pq_init(void) {
    PQ *p = (PQ *)malloc(sizeof(PQ));
    p->index = 0;
    p->capacity = PQSIZE;
    return p;
}

int  pq_maximum(PQ *A) {
    if (A != NULL) {
        return A->data[0];
    }
    return -1; // assume -1 is error
}

/**
 *  1, 将最后一个元素赋值到第一个元素
 *  2, 向下调整堆的特性
 */
int  pq_extract_max(PQ *A) {
    if (A != NULL) {
        int max = A->data[0];
        if (A->index > 0) {
            A->data[0] = A->data[A->index];
            A->index--;
            max_heapify(A->data, 0, A->index);
        }
        return max;
    }
    return -1;
}

/**
 *   1; i为根节点，则无需调整.（因为值只会更大）
 *   2; 当i不为根节点时，增加A[i]的值，则有可能会比父节点大，需要向上调整.
 */
int  pq_increase_key(PQ *A, int i, int key) {
    if (A != NULL && i <= A->index && A->data[i] < key) {
        A->data[i] = key;
        while (i > 0 && A->data[PARENT(i)] < A->data[i]) {
            swap(A->data, i, PARENT(i));
            i = PARENT(i);
        }
        return 0;
    }
    return -1;
}

void pq_insert(PQ *A, int key) {
    if (A != NULL) {
        A->index++;
        if (A->index < A->capacity) {
            A->data[A->index] = -32768; // assume very low
            pq_increase_key(A, A->index, key);
        }
    }
}

void pq_release(PQ *A) {
    if (A != NULL) {
        free(A);
    }
}

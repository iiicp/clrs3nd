#include "primer.h"

int next_primer(int N) {
    if (N % 2 == 0) {
        N++;
    }
    
    for (; ; N+=2) {
        for (int i = 3; i * i <= N; i+=2) {
            if ( N % i == 0) {
                goto ContOuter;
            }
        }
        return N;
    ContOuter: ;
    }
}

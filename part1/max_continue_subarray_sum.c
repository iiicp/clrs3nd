#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a) >= (b) ? (a) : (b)

typedef struct{
    int low;
    int high;
    int sum;
}ThreeTuple;

ThreeTuple max_continue_sub_arr_sum_exhaustion(int *A, int len);
ThreeTuple max_continue_sub_arr_sum_exhaustion_optimization(int *A, int len);
ThreeTuple find_max_crossing_sub_array(int *A, int low, int mid, int high);
ThreeTuple max_continue_sub_arr_sum_dc(int *A, int low, int high);
ThreeTuple max_continue_sub_arr_sum_dp(int *A, int len);


int main(int argc, const char * argv[]) {
    
    int a[10] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    
    ThreeTuple t1 = max_continue_sub_arr_sum_exhaustion(a, 10);
    printf("穷举法(O(n^3)):    %d, %d, %d\n", t1.low, t1.high, t1.sum);
    ThreeTuple t2 = max_continue_sub_arr_sum_exhaustion_optimization(a, 10);
    printf("穷举法(优化 O(n^2)): %d, %d, %d\n", t2.low, t2.high, t2.sum);
    ThreeTuple t3 = max_continue_sub_arr_sum_dc(a, 0, 10);
    printf("分治法(O(nlgn)):   %d, %d, %d\n", t3.low, t3.high, t3.sum);
    ThreeTuple t4 = max_continue_sub_arr_sum_dp(a, 10);
    printf("动态规划(O(n)): %d, %d, %d\n", t4.low, t4.high, t4.sum);

    return 0;
}

ThreeTuple max_continue_sub_arr_sum_exhaustion(int *A, int len)
{
    int max_sum = -32768;
    int left = 0, right = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            int t_sum = 0;
            for (int k = i; k <= j; ++k) { // [i, j]
                t_sum += A[k];
            }
            if (max_sum < t_sum) {
                max_sum = t_sum;
                left = i;
                right = j;
            }
        }
    }
    ThreeTuple tuple = {.low = left, .high = right, .sum = max_sum};
    return tuple;
}

ThreeTuple max_continue_sub_arr_sum_exhaustion_optimization(int *A, int len) {
    int max_sum = -32768;
    int left = 0, right = 0;
    for (int i = 0; i < len; ++i) {
        int t_sum = 0;
        for (int j = i; j < len; ++j) { // [i, j)
            t_sum += A[j];
            if (max_sum < t_sum) {
                max_sum = t_sum;
                left = i;
                right = j;
            }
        }
    }
    ThreeTuple tuple = {.low = left, .high = right, .sum = max_sum};
    return tuple;
}

// [low, mid) [mid, high)
ThreeTuple find_max_crossing_sub_array(int *A, int low, int mid, int high) {
    int left_sum = -32768;
    int sum = 0;
    int max_left = 0;
    for (int i = mid-1; i>=low; --i) {
        sum += A[i];
        if (left_sum < sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    
    int right_sum = -32768;
    sum = 0;
    int max_right = 0;
    for (int i = mid; i < high; ++i) {
        sum += A[i];
        if (right_sum < sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    
    ThreeTuple tuple = {.low = max_left, .high = max_right, .sum = left_sum + right_sum};
    return tuple;
}

ThreeTuple max_continue_sub_arr_sum_dc(int *A, int low, int high) {
    if (high - low == 1) {
        ThreeTuple tuple = {.low = low, .high = high, .sum = A[low]};
        return tuple;
    }else {
        int mid = low + (high - low) / 2;
        ThreeTuple left_part = max_continue_sub_arr_sum_dc(A, low, mid);
        ThreeTuple right_part = max_continue_sub_arr_sum_dc(A, mid, high);
        ThreeTuple cross_part = find_max_crossing_sub_array(A, low, mid, high);
        
        if (left_part.sum >= right_part.sum && left_part.sum >= cross_part.sum) {
            return left_part;
        }else if (right_part.sum >= left_part.sum && right_part.sum >= cross_part.sum) {
            return right_part;
        }else {
            return cross_part;
        }
    }
}

// DP[i] = max{DP[i-1] + A[i], A[i]}
// 求出dp数组，从dp数组里面找出最优值即可
// left即取A[i]的时候
// right即取最大值的时候
ThreeTuple max_continue_sub_arr_sum_dp(int *A, int len) {

    if (len == 0) {
        ThreeTuple t = {.low = 0, .high = 0, .sum = 0};
        return t;
    }
    
    int *dp = (int *)malloc(sizeof(int) * len);
    dp[0] = A[0];
    
    int left = 0, right = 0, sum = A[0];
    
    // 求出dp数组，并且确定左右索引和dp最大值
    for (int i = 1; i < len; ++i) {
        if (dp[i-1] + A[i] < A[i]) {
            dp[i] = A[i];
            left = i;
            right = i;
        }else {
            dp[i] = dp[i-1] + A[i];
            if (sum < dp[i]) {
                sum = dp[i];
                right = i;
            }
        }
    }
    
    free(dp);
    
    ThreeTuple t = {.low = left, .high = right, .sum = sum};

    return t;
}

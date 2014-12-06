/*
 * Source: https://oj.leetcode.com/problems/maximum-product-subarray/
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.

 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
 *
 */

// -2 1 -3 4 -1 2 1 -5 4

#include<iostream>
#include<cmath>

using namespace std;
//2 3 -2 4
int maxProduct(int A[], int n) {
    if(A == NULL || n == 0)
        return 0;

    if(n == 1)
        return A[0];

    int max_local = A[0];
    int min_local = A[0];
    int global = A[0];

    for(int i = 1; i < n; i++) {
        int max_cpy = max_local;
        max_local = max(max(max_local * A[i], A[i]), A[i] * min_local);
        min_local = min(min(max_cpy * A[i], A[i]), A[i] * min_local);

        global = max(max_local, global);
    }

    return global;
}

int main(int argc, char *argv[]) {

    int A[] = {2,3,-2,4};

    cout<<maxProduct(A, 4);
    return 0;
}

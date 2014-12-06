/*
 * Source: https://oj.leetcode.com/problems/maximum-product-subarray/
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.

 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
 *
 */

#include<iostream>
#include<math.h>

using namespace std;
//2 3 -2 4
int maxProduct(int A[], int n) {
    int result = A[0];
    int min = A[0];

    for(int i = 1; i < n; i++) {
        if(result * A[i] * min < A[i]) {
            result = A[i];

            
        }
    }

    return result;
}

int main(int argc, char *argv[]) {

    int A[] = {2,3,-2,4};

    //cout<<maxProduct(A, 4);
    Math.min(3, 4);
    return 0;
}

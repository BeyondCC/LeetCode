/*
 * Source:https://oj.leetcode.com/problems/maximum-product-subarray://oj.leetcode.com/problems/maximum-subarray/ 
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 */


#include<iostream>
#include<cmath>

using namespace std;
//2 3 -2 4

int maxSubArray(int A[], int n) {
    if(A == NULL || n == 0)
        return 0;

    if(n == 1)
        return A[0];

    //local is the best solution while contain current element
    int local = A[0];
    int global = A[0];

    for(int i = 1; i < n; i++) {
        local = max(A[i], local + A[i]);
        global = max(global, local);
    }

    return global;
}

int main(int argc, char *argv[]) {

    int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout<<maxSubArray(A, 9)<<endl;
    return 0;
}

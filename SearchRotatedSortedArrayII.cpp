/*
 * Source: https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * Description:
 * Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;


//time: o(lgn)
bool search(int A[], int n, int target) {
    int start = 0, end = n -1;
    int middle = (start + end) / 2;

    while(start <= end) {
        if (A[middle] == target) {
            return true;
        }

        if (A[middle] < A[end]) { // ]) {//如果右边有序，则判断target是否在其中，若在则start = middle + 1，否则en
            if (A[middle] < target && A[end] >= target) {
                start = middle + 1;
            }else
                end = middle - 1;
        }else if(A[middle] > A[end]){
            if (A[middle] > target && A[start] <= target) {
                end = middle - 1;
            }else
                start = middle + 1;
        }else{
            end--;
        }

        middle = (start + end) / 2;
    }

    return false;
}

int main(int argc, char *argv[]) {
    
    int A[] = { 3,1, 1}; 

    cout<<"index is "<<search(A, 3, 3);

    return 0;
}


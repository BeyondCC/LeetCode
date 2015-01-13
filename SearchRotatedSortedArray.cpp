/*
 * Source:https://oj.leetcode.com/problems/search-in-rotated-sorted-array/ 
 * Description:
 * 
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;


//time: o(lgn)
int search(int A[], int n, int target) {
    int start = 0, end = n -1;
    int middle = (start + end) / 2;

    while(start <= end) {
        if (A[middle] == target) {
            return middle;
        }

        if (A[middle] < A[end]) { // ]) {//如果右边有序，则判断target是否在其中，若在则start = middle + 1，否则en
            if (A[middle] < target && A[end] >= target) {
                start = middle + 1;
            }else
                end = middle - 1;
        }else {
            if (A[middle] > target && A[start] <= target) {
                end = middle - 1;
            }else
                start = middle + 1;
        }
        
        middle = (start + end) / 2;
    }

    return -1;
}

int main(int argc, char *argv[]) {
    
    int A[] = {8,2,3,4,5,6,7};

    cout<<"index is "<<search(A, 7, 3);

    return 0;
}


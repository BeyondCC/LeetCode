/*
 * Source: https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
 * Description: 
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

int helper(int A[], int startOfA, int endOfA, int B[], int startOfB, int endOfB, int k) {
    int lenOfA = endOfA - startOfA + 1;
    int lenOfB = endOfB - startOfB + 1;

    // 确保A的长度比B的短,从而当lenOfA == 0时直接返回B的对应数字
    if (lenOfB < lenOfA)
    {
        return helper(B, startOfB, endOfB, A, startOfA, endOfA, k);   
    }
    //返回B从startOfB开始的第k个数
    if (lenOfA == 0)
    {
        return B[startOfB + k - 1];   
    }

    //返回A和B最小的数字
    if (k == 1)
    {
        return min(A[startOfA], B[startOfB]);   
    }

    int posA = min(lenOfA, k / 2);
    int posB = k - posA;

    if (A[startOfA + posA - 1] == B[startOfB + posB - 1])
    {
        return  A[startOfA + posA - 1];  
    }else if (A[startOfA + posA - 1] > B[startOfB + posB - 1]) {
        //B的前posA个元素不可能出现最终结果，弃之
        return helper(A, startOfA, startOfA + posA - 1, B, startOfB + posB, endOfB, k - posB);
    }else
        return helper(A, startOfA + posA, endOfA, B, startOfB, startOfB + posB - 1, k - posA);

}

//每次去除 2/k, time：O（lgk), 即（lg(m + n) / 2）
double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ((m + n) % 2  == 1)
    {   
        return helper(A, 0, m - 1, B, 0, n -1, (m + n) / 2 + 1);
    }else{
        return (helper(A, 0, m - 1, B, 0, n -1, (m + n) / 2) + helper(A, 0, m -1, B, 0, n -1, (m+ n) / 2 + 1)) / 2.0;
    }   
}

int main(int argc, char *argv[]) {
    int A[] = {};
    int B[] = {1};

    cout<<"result is "<<findMedianSortedArrays(A, 0, B, 1)<<endl;
    return 0;
}


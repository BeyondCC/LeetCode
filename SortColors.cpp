/*
 * Source: https://oj.leetcode.com/problems/sort-colors/ 
 * Description:
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

//计数排序, 扫描三遍，O（n * 3）, space O(n)
void sortColors(int A[], int n) {
    int *helper = new int[3];
    int *res = new int[n];

    for (int i = 0; i < 3; ++i)
    {
        helper[i] = 0;   
    }

    for (int i = 0; i < n; ++i)
    {
        helper[A[i]]++;      
    }

    for (int i = 1; i < 3; ++i)
    {
        helper[i] += helper[i - 1];   
    }

    for (int i = n - 1;i >= 0; i--)
    {
        res[helper[A[i]] - 1] = A[i];
        helper[A[i]]--;
    }

    for (int i = 0; i < n; ++i)
    {
        A[i] = res[i];             
    }

}

//one pass to get the result  O(n), space o(k)
void sort(int A[], int n) {

    int index1 = 0;
    int index0 = 0;

    for (int i = 0; i  < n; ++i )
    {
        if (A[i] == 0)
        {
            A[i] = 2;
            A[index1++] = 1;
            A[index0++] = 0;
        }else if (A[i] == 1)
        {
            A[i] = 2;
            A[index1++] = 1;
        }   
    }
}

void printArr(int A[], int n) {
    for (int i = 0; i < n; ++i)
    {
        cout<<A[i]<<" ";   
    }

    cout<<endl;
}

int main(int argc, char *argv[]) {
    int A[] = {0, 1, 2, 0, 0, 1, 1, 2, 2};

    //sortColors(A, 9);
    sort(A, 9);
    printArr(A, 9);
    return 0;
}


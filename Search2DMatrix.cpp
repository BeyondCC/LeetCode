/*
 * Source:://oj.leetcode.com/problems/search-a-2d-matrix/ 
 * Description:
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

bool binarySearch(vector<int> matrix, int target) {
    
    int start = 0, end = matrix.size() - 1;
    int middle = (start + end) / 2;

    while(start <= end) {
        cout<<"start "<<start<<" end:"<<end<<endl;
        cout<<"start "<<matrix[start]<<" end:"<<matrix[end]<<endl;
        if (matrix[middle] == target) {
            return true;
        }else if (matrix[middle] > target) {
            end = middle -1;
        }else{
            start = middle + 1;
        }

        middle = (start + end) / 2;
    }

    return false;
}

//先行进行二叉查找，然后列二叉查找 time o(lgm + lgn)
bool searchMatrix(vector<vector<int> > &matrix, int target) {
    
    if (matrix.size() == 0) {
        return false;
    }

    int start = 0, end = matrix.size() -1;
    int middle;
    while(start <= end) {
        middle = (start + end) / 2;
        if (matrix[middle][0] == target) {
            return true;
        }else if (matrix[middle][0] < target) {
            start = middle + 1;
        }else {
            end = middle -1;
        }
    }

    //前一个查找中，要么查到，要么就是在可能的matrix[end]这一行中进行查找（小于和大于target两种情况会对应end 是唯一可能的）
    int row = end;

    if (row < 0) {
        return false;
    }

    return binarySearch(matrix[row], target);;
}

int main(int argc, char *argv[]) {

    vector<int > v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);

    vector<int > v1;

    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(16);
    v1.push_back(20);
    vector<int > v2;

    v2.push_back(23);
    v2.push_back(30);
    v2.push_back(34);
    v2.push_back(50);

    vector<vector<int> > vec;

    vec.push_back(v);
    vec.push_back(v1);
    vec.push_back(v2);

    cout<<"result is "<<searchMatrix(vec, 30);

    return 0;
}


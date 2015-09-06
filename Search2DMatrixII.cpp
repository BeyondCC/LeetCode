/* 
 * Author: cc
 * Date  : 2015-09-06
 * Source: https://leetcode.com/problems/search-a-2d-matrix-ii/
 * Description:
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

 Integers in each row are sorted in ascending from left to right.
 Integers in each column are sorted in ascending from top to bottom.
 For example,

 Consider the following matrix:

 [
   [1,   4,  7, 11, 15],
     [2,   5,  8, 12, 19],
       [3,   6,  9, 16, 22],
         [10, 13, 14, 17, 24],
           [18, 21, 23, 26, 30]

 ]
 Given target = 5, return true.

 Given target = 20, return false.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        //因为每行从左到右增长，从上到下增长
        // 从右上角开始进行比较，要么左移要么下移，时间复杂度o(m + n)
        bool searchMatrix(vector<vector<int> >& matrix, int target) {
            if (matrix.size() == 0) {
                return false;
            }

            int rows = matrix.size();
            int cols = matrix[0].size();

            int row = 0;
            int col = cols - 1;

            while(row < rows && col >= 0) {
                if (matrix[row][col] < target) {
                    row++;
                }else if(matrix[row][col] > target) {
                    col--;
                }else {
                    return true;
                }
            }

            return false;
        }

};

int main(int argc, char *argv[]) {
    return 0;
}


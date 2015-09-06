/* 
 * Author: cc
 * Date  : 2015-09-05
 * Source: https://leetcode.com/problems/spiral-matrix/
 * Description:
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

 For example,
 Given the following matrix:

 [
  [ 1, 2, 3  ],
   [ 4, 5, 6  ],
    [ 7, 8, 9  ]

 ]
 You should return [1,2,3,6,9,8,7,4,5].
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
        vector<int> spiralOrder(vector<vector<int> >& matrix) {
            int levels = matrix.size();
            vector<int> res;

            if (matrix.size() == 0 || matrix[0].size() == 0) {
                return res;
            }
            int rowLen = matrix[0].size();
            int minLen = min(levels, rowLen);
            int rows = minLen / 2;

            for (int i = 0; i < rows; ++i) {
                // left -> right
                for (int j = i; j < matrix[i].size() - i - 1; ++j) {
                    res.push_back(matrix[i][j]);
                }
                //top -> down
                for (int j = i; j < levels - i - 1; ++j) {
                    res.push_back(matrix[j][matrix[0].size() - 1 - i]); 
                }
                // right -> left
                for (int j = matrix[i].size() - 1 - i; j > i; j--) {
                    res.push_back(matrix[levels - 1 - i][j]); 
                }
                //down -> top
                for (int j = levels - 1 - i;  j  > i ; j--) {
                    res.push_back(matrix[j][i]); 
                }
            }

            if (minLen % 2 != 0) {
                if (levels < rowLen) {
                    for (int i = rows; i < rowLen - rows; ++i) {
                        //从左到右
                        res.push_back(matrix[rows][i]); 
                    }
                }else{
                    for (int i = rows; i < levels - rows; ++i) {
                        //从右到左
                        res.push_back(matrix[i][rows]);
                    }
                }
            }

            for (int i = 0; i < res.size(); ++i) {
                cout<<res[i]<<" "; 
            }
            cout<<endl;

            return res;
        }

};

int main(int argc, char *argv[]) {
    int a[] = {1};
    int b[] = {2};
    int c[] = {3};
    int d[] = {4};

    vector<vector<int> > matrix;
    vector<int> row1(a, a + 1);
    vector<int> row2(b, b  + 1);
    vector<int> row3(c, c + 1);
    vector<int> row4(d, d + 1);
    

    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);

   
    Solution s;
    s.spiralOrder(matrix);

    return 0;
}


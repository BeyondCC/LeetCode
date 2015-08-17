/* 
 * Author: cc
 * Date  : 2015-08-16
 * Source: https://leetcode.com/problems/n-queens-ii/
 * Description: 
 * Follow up for N-Queens problem.

 Now, instead outputting board configurations, return the total number of distinct solutions.
 ]'
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
        int totalNQueens(int n) {
            vector<vector<string> > res;
            vector<int> tmp(n);
            int count = 0;
            helper(n, 0, tmp, count);
            
            return count;
        }

        bool check(int row, vector<int> tmp) {
            for (int i = 0; i < row; ++i) {
                //检查第row行跟前面的行是否冲突，同一列，对角线
                if (tmp[row] == tmp[i] || abs(tmp[row] - tmp[i]) == row - i) {
                    return false;
                }
            }    

            return true;
        }

        void helper(int n,int row, vector<int> &tmp, int &count){
            if (row == n) {
                count++;
                return;
            }

            for (int i = 0; i < n; ++i) {
                tmp[row] = i;
                //每插入一行都正确
                if (check(row, tmp)) {
                    helper(n, row + 1, tmp, count);
                }
            } 
        }

};

int main(int argc, char *argv[]) {

    Solution s;

    return 0;
}


/* 
 * Author: cc
 * Date  : 2015-08-16
 * Source: https://leetcode.com/problems/n-queens/
 * Description: 
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



 Given an integer n, return all distinct solutions to the n-queens puzzle.

 Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 
 For example,
 There exist two distinct solutions to the 4-queens puzzle:
 
 [
  [".Q..",  // Solution 1
    "...Q",
      "Q...",
        "..Q."],

         ["..Q.",  // Solution 2
           "Q...",
             "...Q",
               ".Q.."]

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
        vector<vector<string> > solveNQueens(int n) {
            vector<vector<string> > res;
            vector<int> tmp(n);
            cout<<tmp.size()<<endl;
            helper(n, 0, tmp, res);

            cout<<res.size()<<endl;
            for (int i = 0; i < res.size(); ++i) {
                vector<string> tmp = res[i];
                for (int j = 0; j < tmp.size(); ++j) {
                    cout<<tmp[j]<<endl;
                } 

                cout<<endl;
            }
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

        void helper(int n,int row, vector<int> &tmp, vector<vector<string> > &res) {
            if (row == n) {
                vector<string> one_res;
                for (int i = 0; i < tmp.size(); ++i) {
                    string s(n, '.');
                    s[tmp[i]] = 'Q';

                    one_res.push_back(s);
                }

                res.push_back(one_res);
                return;
            }

            for (int i = 0; i < n; ++i) {
                tmp[row] = i;
                //每插入一行都正确
                if (check(row, tmp)) {
                    helper(n, row + 1, tmp, res);
                }
            } 
        }

};

int main(int argc, char *argv[]) {

    Solution s;
    s.solveNQueens(8);

    return 0;
}


/* 
 * Author: cc
 * Date  : 2015-03-06
 * Source: https://oj.leetcode.com/problems/sudoku-solver/
 * Description:
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 * 核心思想跟N皇后一致，每个节点进行检查，跟之前所有的节点判断是否冲突
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool check(vector<vector<char> > board, int row, int col);
bool helper(vector<vector<char> > &board, int row, int col);

void solveSudoku(vector<vector<char> > &board) {
    if (board.size() != 9 || board[0].size() != 9) {
        return;
    }
    helper(board, 0, 0);
}

bool helper(vector<vector<char> > &board, int row, int col) {
    if (row == 9) {
        return true;
    }

    if (col >= 9) {
        return helper(board, row + 1, 0);
    }

    if (board[row][col] == '.') {
        for (int i = 1; i <= 9; ++i) {
            board[row][col] = '0' + i;
            if (check(board, row, col)) {
                if (helper(board, row, col + 1))
                    return true;
            }
            //just reset
            board[row][col] = '.';
        }
    }else{
        return helper(board, row, col + 1);
    }

    return false;
}

bool check(vector<vector<char> > board, int row, int col) {
    //check row 
    for (int i = 0; i < 9; ++i) {
        if (board[i][col] == board[row][col] && row != i) {
            return false;
        }
    }

    //check col
    for (int i = 0; i < 9; ++i) {
        if (col != i && board[row][col] == board[row][i]) {
            return false;
        }
    }

    //check block
    for (int i = row / 3 * 3; i < row / 3 * 3 + 3; ++i) {
        for (int j = col / 3 * 3; j < col / 3 * 3 + 3; ++j) {
            if ((row != i || col != j) && board[row][col] == board[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
   char a = '0' + 1;

   cout<<a<<endl;
    return 0;
}


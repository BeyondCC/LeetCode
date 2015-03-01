/* 
 * Author: cc
 * Date  : 2015-03-01
 * Source: https://oj.leetcode.com/problems/valid-sudoku/
 * Description:
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * 
 * each row, col, 3 * 3 grids should only contain 0 ~ 9
 *
 * A partially filled sudoku which is valid.
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board) {
    bool result = true;

    int length = board.size();

    if (length != 9)
    {
        return false;
    }

    if (board[0].size() != 9)
    {
        return false;
    }
    
    //check the row
    for (int i = 0; i < board.size(); ++i)
    {
        unordered_map<char, int> rowMap;
        for (int j = 0; j < board.size(); ++j)
        {
            if (board[i][j] != '.') 
            {
                if (rowMap.find(board[i][j]) == rowMap.end())
                {
                    rowMap.insert(make_pair(board[i][j], 1));
                }else{
                    return false;
                }
            }
        }
    }

    //check the coloumn
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board.size(); ++j)
        {    
            unordered_map<char, int> colMap;
            for (int j = 0; j < board.size(); ++j)
            {
                if (board[j][i] != '.') 
                {
                    if (colMap.find(board[j][i]) == colMap.end())
                    {
                        colMap.insert(make_pair(board[j][i], 1));
                    }else{
                        return false;
                    }
                }
            }
        }
    }

    //check the 3 * 3 grids

    for (int i = 0; i < board.size(); i += 3)
    {
        for (int j = 0; j < board.size(); j += 3)
        {
            unordered_map<char, int> gridMap;
            for(int row = i; row < i + 3; row++)
            {
                for (int col = j; col < j + 3; col++)
                {
                    if (board[row][col] != '.')
                    {
                        if (gridMap.find(board[row][col]) == gridMap.end())
                        {
                            gridMap.insert(make_pair(board[row][col], 1));
                        }else{
                            return false;
                        }
                    }
                }
            }
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    vector<vector<char> > board;
    vector<char> row;

    row.push_back('5');
    row.push_back('3');
    row.push_back('.');
    row.push_back('.');
    row.push_back('7');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');

    board.push_back(row);

    vector<char> row1;

    row1.push_back('6');
    row1.push_back('.');
    row1.push_back('.');
    row1.push_back('1');
    row1.push_back('9');
    row1.push_back('5');
    row1.push_back('.');
    row1.push_back('.');
    row1.push_back('.');

    board.push_back(row1);

    vector<char> row2;

    row2.push_back('.');
    row2.push_back('9');
    row2.push_back('8');
    row2.push_back('.');
    row2.push_back('.');
    row2.push_back('.');
    row2.push_back('.');
    row2.push_back('6');
    row2.push_back('.');

    board.push_back(row2);

    vector<char> row3;

    row3.push_back('8');
    row3.push_back('.');
    row3.push_back('.');
    row3.push_back('.');
    row3.push_back('6');
    row3.push_back('.');
    row3.push_back('.');
    row3.push_back('.');
    row3.push_back('3');

    board.push_back(row3);

    vector<char> row4;

    row4.push_back('4');
    row4.push_back('.');
    row4.push_back('.');
    row4.push_back('8');
    row4.push_back('.');
    row4.push_back('3');
    row4.push_back('.');
    row4.push_back('.');
    row4.push_back('1');

    board.push_back(row4);
    
    vector<char> row5;

    row5.push_back('.');
    row5.push_back('9');
    row5.push_back('8');
    row5.push_back('.');
    row5.push_back('.');
    row5.push_back('.');
    row5.push_back('.');
    row5.push_back('6');
    row5.push_back('.');

    board.push_back(row5);
    return 0;
}


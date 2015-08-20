/* 
 * Author: cc
 * Date  : 2015-08-20
 * Source: https://leetcode.com/problems/word-search/
 * Description:
 * Given a 2D board and a word, find if the word exists in the grid.

 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

 For example,
 Given board =

 [
   ["ABCE"],
     ["SFCS"],
       ["ADEE"]

 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.
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
        bool exist(vector<vector<char> >& board, string word) {
            vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
            bool res = false; 
            helper(board, 0, 0, visited, word, 0, res);

            return res;
        }

        void helper(vector<vector<char> > &board, int row, int col, vector<vector<bool> > &visited, string word, int start, bool &res) {
            if (start == word.size()) {
                res = true;
                return;
            } 
            if (row < 0 || col <0 || row >= board.size() || col >= board[0].size()) {
                return; 
            }

            
            cout<<"row:"<<row<<" col:"<<col<<endl;
            //cout<<board.size()<<endl;
            cout<<board[row][col]<<endl;
            if (start == 0) {
                for (int i = 0; i < board.size(); ++i) {
                    vector<char> row = board[i];
                    for (int j = 0; j < row.size(); ++j) {
                        if (board[i][j] == word[start] && !visited[i][j]) {
                            visited[i][j] = true;
                            cout<<"hereee"<<endl;
                            helper(board, i, j + 1, visited, word, start + 1, res);
                            if (res) {
                                return;
                            }
                            helper(board, i + 1, j, visited, word, start + 1, res);
                            if (res) {
                                return;
                            }
                            helper(board, i, j - 1, visited, word, start + 1, res);
                            if (res) {
                                return;
                            }
                            helper(board, i - 1, j, visited, word, start + 1, res);
                            if (res) {
                                return;
                            }

                            visited[i][j] = false;
                        }
                    }
                }
            }else{
                if (board[row][col] == word[start] && !visited[row][col]) {
                    visited[row][col] = true;
                    helper(board, row, col + 1, visited, word, start + 1, res);
                    if (res) {
                        return;
                    }
                    helper(board, row - 1, col, visited, word, start + 1, res);
                    if (res) {
                        return;
                    }
                    helper(board, row + 1, col, visited, word, start + 1, res);
                    if (res) {
                        return;
                    }
                    helper(board, row, col - 1, visited, word, start + 1, res);
                    if (res) {
                        return;
                    }
                    visited[row][col] = false;
                }
            }
        }
};

int main(int argc, char *argv[]) {
    vector<vector<char> > boards;
    char A[] = {'A', 'B', 'C', 'E'};
    char B[] = {'S', 'F', 'C', 'S'};
    char C[] = {'A', 'D', 'E', 'E'};
    
    //vector<char> row1(&A[0], &A[4]);
    //vector<char> row2(&B[0], &B[4]); 
    //vector<char> row3(&C[0], &C[4]);
    vector<char> row4(1, 'a');
    row4.push_back('b');

    //boards.push_back(row1);
    //boards.push_back(row2);
    //boards.push_back(row3);
    boards.push_back(row4);

    string word("ABCCED");
    string word1("SEE");
    string word2("ABCB");
    string word3("ba");
    Solution s;
    cout<<"result:"<<s.exist(boards, word3)<<endl;
    return 0;
}


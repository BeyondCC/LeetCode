/* 
 * Author: cc
 * Date  : 2015-08-13
 * Source: https://leetcode.com/problems/maximal-square/
 * Description:
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

 For example, given the following matrix:

 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0
 Return 4.
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
        int maximalSquare(vector<vector<char> >& matrix) {
            int res = 0;
            int M = matrix.size();
            if (M == 0 || matrix[0].size() == 0) {
                return res;
            }
            int N = matrix[0].size();

            vector<vector<int> > dp(M, vector<int>(N, 0));

            for (int i = 0; i < matrix[0].size(); ++i) {
                if (matrix[0][i] == '1') {
                    dp[0][i] = 1;
                    res = 1;
                }    
            }

            for (int i = 0; i < M; ++i) {
                if (matrix[i][0] == '1') {
                    dp[i][0] = 1;
                    res = 1;
                }
            }

            //dp[i][j] 代表在i,j为右下角的最大正方形的边长
            for (int i = 1; i < M; ++i) {
                for (int j = 1; j < N; ++j) {
                    if (matrix[i][j] == '1') {
                        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                        res = max(res, dp[i][j]);
                    }
                }
            }

            return res * res;
        }

};

int main(int argc, char *argv[]) {
    return 0;
}


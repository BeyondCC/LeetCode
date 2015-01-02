/*
 * Source: https://oj.leetcode.com/problems/distinct-subsequences/
 * Description: Given a string S and a string T, count the number of distinct subsequences of T in S.

 A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

 Here is an example:
 S = "rabbbit", T = "rabbit"

 Return 3.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>

using namespace std;

int numDistinct(string S, string T) {
    if(S.size() < T.size()) 
        return 0;

    int *dp = new int[T.size() + 1];
    for(int i = 0; i < T.size() + 1; i++)
        dp[i] = 0;

    dp[0] = 1;

    for(int i = 0; i < S.size(); i++){
        // from end to start, is to use the old data:dp[i - 1][j - 1] and dp[i - 1][j]
        // from start to end , is to use the update data:
        for(int j = T.size() - 1; j >= 0; j--) {
            //if S[i] == T[j] ? dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
            //if s[i] != T[j] ? dp[i][j] = dp[i - 1][j]
            dp[j + 1] = (S[i] == T[j] ? dp[j] : 0) + dp[j + 1];
        }
    }

    return dp[T.size()];
}

int main(int argc, char *argv[]) {
    string s = "b", t = "b";
    cout<<"result is "<<numDistinct(s, t)<<endl;
    return 0;
}


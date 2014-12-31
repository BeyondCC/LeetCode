/*
 * Source: https://oj.leetcode.com/problems/interleaving-string/
 * Description: Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

 For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    if(s1.size() + s2.size() != s3.size())
        return 0;

    if(s1.size() == 0 &&  s2.size() == 0 &&  s3.size() == 0)
        return 1;
    int **dp = new int*[s1.size() + 1];

    for(int i = 0; i < s1.size() + 1; i++) {
        dp[i] = new int[s2.size() + 1];
        for(int j = 0; j < s2.size() + 1; j++){
            dp[i][j] = 0;
        }
    }

   for(int i = 0; i < (s1.size() + 1); i++) {
        for(int j = 0; j < (s2.size() + 1);j++) {
            if(i == 0 && j == 0) {
                dp[0][0] = 0;
            }else if(i == 0) {
                if(s2[j - 1] == s3[j - 1])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }else if(j == 0) {
                if(s1[i - 1] == s3[i - 1]) 
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }else if((dp[i][j - 1] && s2[j - 1] == s3[i + j - 1] ) || (dp[i - 1][j] &&s1[i - 1] == s3[i + j - 1])) {
                dp[i][j] = 1;
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[s1.size()][s2.size()];   
}

int main(int argc, char *argv[]) {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    cout<<"result is "<<isInterleave(s1, s2, s3);
    return 0;
}


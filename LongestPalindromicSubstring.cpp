/*
 * Source: https://oj.leetcode.com/problems/longest-palindromic-substring/
 * Description: Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>

using namespace std;

/*
 * time: 0(n^2), space O(n ^ 2)
 *
 */
string longestPalindrome(string s) {
    int size = s.size();
    bool **dp = new bool*[size];

    string res;
    int maxLen = 0;

    for (int i = 0; i < size; i++) {
        dp[i] = new bool[size];
        for (int j = 0; j < size; j++) {
            dp[i][j] = false;
        }
    }

    //从后往前纪录从s[i]到s[size]是否是回文串
    //如果s[i] == s[j]并且s[i + 1][j - 1] = true || j - i <= 2,则为true，更新最大串信息
    for (int i = size - 1; i >= 0; i--) {
        for (int j = i; j < size; j++) {
            if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])){
                dp[i][j] = true;

               if (maxLen < j - i + 1) {
                    maxLen = j - i + 1;
                    res = s.substr(i, j - i + 1);
                    cout<<"res is "<< res<<endl;
                }
            }
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
    string s = "asfabcddcba";
    cout<<"result is "<<longestPalindrome(s)<<endl;
    return 0;
}


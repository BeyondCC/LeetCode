/*
 * Source: https://oj.leetcode.com/problems/edit-distance/
 * Description: Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

 You have the following 3 operations permitted on a word:

 a) Insert a character
 b) Delete a character
 c) Replace a character
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>

using namespace std;


//time O(m * n), space O(min(m, n))
int minDistance(string word1, string word2) {
    if(word1.size() == 0)
        return word2.size();

    if(word2.size() == 0) 
        return word1.size();

    string maxStr = word1.size() > word2.size() ? word1 : word2;
    string minStr = word1.size() > word2.size() ? word2 : word1;

    //初始化条件为最小字符串转换为空串，dp[i] = i
    int *dp = new int[minStr.size() + 1];
    for(int i = 0; i < minStr.size() + 1; i++){
        dp[i] = i;
    }

    for(int i = 0; i < maxStr.size(); i++) {
        int *newDp = new int[minStr.size() + 1];
        //dp保存上一行的信息，newDp保存这一行的信息，因为要拿dp[i - 1][j],dp[i][j - 1], dp[i][j - 1]
        //newDp[0]代表当前长串要转换成空串的步数，显然是dp[i + 1]
        newDp[0] = i + 1;
        for(int j = 0; j < minStr.size(); j++) {
            if(maxStr[i] == minStr[j]) {
                newDp[j + 1] = dp[j];
            }else{
                newDp[j + 1] = min(dp[j], min(dp[j + 1], newDp[j])) + 1;
            }
        }   
        //更新上一行的信息
        dp = newDp;
    }

    return dp[minStr.size()];
}

int main(int argc, char *argv[]) {
    string s1 = "abcde", s2 = "bcda";
    cout<<"min distance is "<<minDistance(s1, s2);
    return 0;
}


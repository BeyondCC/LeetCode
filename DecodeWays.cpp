/*
 * Source: https://oj.leetcode.com/problems/decode-ways/
 * Description: A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 *
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int numDecodings(string s) {
    int size = s.length();
    int *dp = new int[size + 1];

    if(size == 0)
        return 0;

    dp[0] = 1;
    if(s[0] != '0')
        dp[1] = 1;
    else 
        dp[1] = 0;

    for(int i = 2; i <= size; i++)
    {
        if(s[i - 1] != '0')
            dp[i] = dp[i - 1];
        else
            dp[i] = 0;
//the end consider as a char or two char
        if(s[i - 2] == '1' ||( s[i - 2] == '2' && s[i - 1] <= '6'))
                dp[i] += dp[i -2];
    }

    return dp[size];
}

int main(int argc, char *argv[]) {
    string s = "012";
    cout<<numDecodings(s)<<endl;
    return 0;
}

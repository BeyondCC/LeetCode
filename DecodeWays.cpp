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
    int *p = new int[size];

    if(s == "" || s == "0")
        return 0;

    for(int i = 0; i < s.length(); i++){
        p[i] = 0;
    }

    if(s[0] == '0')
        p[0] = 0;
    else
        p[0] = 1;

    for(int i = 1; i < s.length(); i++) {
        int compose = (s[i - 1] - '0') * 10  + s[i] - '0';
        cout<<compose<<endl;

        if( compose > 26 || compose < 1){
            if(i > 1 && i < s.length() - 1) {
                int preCompose = (s[i - 2] - '0' ) * 10  + s[i - 1] - '0'; 
                if(preCompose > 26 || preCompose < 1)
                    return 0;
                else if(compose > 26 || compose < 1) { 
                    p[i] = p[i - 1] - 1;
        }else if(s[i] == '0'){
            p[i] = p[i - 1];
        }else{
            p[i] = p[i - 1] + 1;
        }

        if(p[i] < 0)
            return 0;
    }

    return p[size - 1];
}

int main(int argc, char *argv[]) {
    string s = "11";
    cout<<numDecodings(s)<<endl;
    return 0;
}

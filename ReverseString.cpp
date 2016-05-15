/* 
 * Author: cc
 * Date  : 2016-05-15
 * Source: https://leetcode.com/problems/reverse-string/
 * Description:
 * Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
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
    string reverseString(string s) {
        if (s.size() == 0)
            return s;

        int start = 0;
        int end   = s.size() - 1;

        while(start < end) {
            swap(s, start, end);
            start++;
            end--; 
        }   

        return s;
    }

    void swap(string &s, int start, int end) {
        char tmp = s[end];
        s[end]   = s[start];
        s[start] = tmp;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
     
    string str("abc");
    cout<<s.reverseString(str)<<endl;
    return 0;
}


/* 
 * Author: cc
 * Date  : 2016-05-15
 * Source: https://leetcode.com/problems/reverse-vowels-of-a-string/
 * Description:
 Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede". 
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
            if (isVowels(s[start]) && isVowels(s[end])) {
                swap(s, start, end);
                start++;
                end--;
                continue;
            }
            
            if (!isVowels(s[start]))
                start++;
        
            if (!isVowels(s[end]))
                end--; 
        }   

        return s;
    }

    bool isVowels(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;

        return false;
    }

    void swap(string &s, int start, int end) {
        char tmp = s[end];
        s[end]   = s[start];
        s[start] = tmp;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
     
    string str("leetcode");
    cout<<s.reverseString(str)<<endl;
    return 0;
}


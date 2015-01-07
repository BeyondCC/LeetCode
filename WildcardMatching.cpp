/* Source: https://oj.leetcode.com/problems/wildcard-matching/
 * Description: Implement wildcard pattern matching with support for '?' and '*'.

 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).

 The matching should cover the entire input string (not partial).

 The function prototype should be:
 bool isMatch(const char *s, const char *p)

 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "*") → true
 isMatch("aa", "a*") → true
 isMatch("ab", "?*") → true
 isMatch("aab", "c*a*b") → false
 *
 */

 
#include<iostream>

using namespace std;

bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s; 
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p = star+1; s=++ss;continue;}                                                                return false;
        }
        while (*p=='*'){p++;}
            return !*p;
}

int main(int argc, char *argv[]) {
    char *s = "aa", *p = "a";

    cout<<"result is "<<isMatch(s, p);
    return 0;
}

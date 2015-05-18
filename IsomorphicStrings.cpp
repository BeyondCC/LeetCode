/* 
 * Author: cc
 * Date  : 2015-05-19
 * Source: https://leetcode.com/problems/isomorphic-strings/
 * Description:
 * Given two strings s and t, determine if they are isomorphic.

 Two strings are isomorphic if the characters in s can be replaced to get t.

 All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

 For example,
 Given "egg", "add", return true.

 Given "foo", "bar", return false.

 Given "paper", "title", return true.


 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> s_dict;
    unordered_map<char, char> t_dict;

    for (int i = 0; i < s.size(); ++i) {
       if (s_dict.find(s[i]) == s_dict.end()) {
           s_dict.insert(make_pair(s[i], t[i]));
       } 

       if (t_dict.find(t[i]) == t_dict.end()) {
           t_dict.insert(make_pair(t[i], s[i]));
       } 

       if (s_dict[s[i]] != t[i] || t_dict[t[i]] != s[i]) {
           return false;
       }
    }
    return true;
}

bool isIsomorphic1(string s, string t) {
    unordered_map<char, int> dict;
    for (int i = 0; i < s.size(); ++i) {
        if (dict.find(s[i]) == dict.end()) {
           for (int j = i + 1; j  < t.size(); ++j) {
               if (!((s[i] == s[j] && t[i] == t[j]) || (s[i] != s[j] && t[i] != t[j]))) {
                    return false;
               }
           }
           dict.insert(make_pair(s[i], 1));
        } 
    }

    return true;
}

int main(int argc, char *argv[]) {
    cout<<isIsomorphic("fooiwrewrwoenriowrniowenrowenroiwneroiwnronewoirnwoirnwernowerniownionoiio", "barqneqmeqmeoqmwennancsncsclkdsclksdcnlkscndlscnldsn")<<endl;
    return 0;
}


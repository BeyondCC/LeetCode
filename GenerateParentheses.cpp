/* 
 * Author: cc
 * Date  : 2015-06-29
 * Source: https://leetcode.com/problems/generate-parentheses/
 * Description:
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 "((()))", "(()())", "(())()", "()(())", "()()()"
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<set>

using namespace std;

set<string> iterGenerateParenthesis(int n) {
    if (n == 1) {
       set<string> s;
       s.insert("()");
       return s;
    } 

    set<string> res = iterGenerateParenthesis(n - 1);
    set<string>::iterator iter;

    set<string> s;
    for(iter = res.begin(); iter != res.end(); iter++)
    {

        for (int i = 0; i < (*iter).length(); ++i) {
            string str = *iter;
            str.insert(i, "()");

            s.insert(str);
        }
    }

    return s;
}

vector<string> generateParenthesis(int n) {
    set<string> s = iterGenerateParenthesis(n); 
    vector<string> res;

    set<string>::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++)
    {
        res.push_back(*iter);
        cout<<*iter<<endl;
    }
    return res;
}

int main(int argc, char *argv[]) {
    generateParenthesis(4);
    return 0;
}


/*
 * Source:
 * Description:
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>

using namespace std;

int longestValidParenthese(string s) {
    stack<int> sta;

    int maxLen = 0;
    int start  = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            //store the index of the char
            cout<<"s[i]"<<s[i] <<"i "<<i<<endl;
            sta.push(i);
        }else{
            if(sta.empty()) {
                start = i + 1;
            }else{
                sta.pop();
                cout<<"top:"<<sta.top()<<" i:"<<i<<endl;
                maxLen = sta.empty() ? max(maxLen, i - start + 1) : max(maxLen, i - sta.top());
            }
        }
    }

    return maxLen;
}

int main(int argc, char *argv[]) {
    string s =  ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())"; 
    cout<<"max len is "<<longestValidParenthese(s);
    return 0;
}


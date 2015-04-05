/* 
 * Author: cc
 * Date  : 2015-04-05
 * Source: https://leetcode.com/problems/count-and-say/ 
 * Description:
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

string nextString(string s) {
    string res = "";

    if (s == "")
        return s;

    int count = 1;
    char preChar = s[0]; 

    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == preChar)
        {
            count++;
        }else{
            res += '0' + count;
            res += preChar;
            preChar = s[i];
            count=1;
        }
    }

    res += '0' + count;
    res += preChar;

    return res;
}

string countAndSay(int n) {
    string s = "1"; 
    if (n == 1)
    {
        return s;
    }

    for (int i = 2; i <= n; ++i)
    {
        s = nextString(s);
        cout<<s<<endl;
    }

    return s;
}

int main(int argc, char *argv[]) {
    cout<<nextString("1211")<<endl;

    countAndSay(8);
    return 0;
}


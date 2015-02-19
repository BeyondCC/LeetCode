/* 
 * Author: cc
 * Date  : 2015-02-15
 * Source: https://oj.leetcode.com/problems/excel-sheet-column-title/
 * Description:
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * For example:
 *
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB 
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string convertToTitle(int n) {
    string res = "";

    while (n) { 
        // 0 ~ 25 is A to Z
        // now 1 ~ 26 is A to Z
        // so minus one to get right answer
        n--;
        int remainder = n % 26;
        int divisor = n / 26;
        
        char ch = 'A' + remainder % 26;
        res += ch;

        n = divisor;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main(int argc, char *argv[]) {
    string s("A");
    cout<<"test size is "<<s.length();
    cout<<convertToTitle(28)<<endl;
    cout<<convertToTitle(26)<<endl;
    cout<<convertToTitle(1)<<endl;
    cout<<convertToTitle(2)<<endl;
    cout<<convertToTitle(3)<<endl;
    return 0;
}


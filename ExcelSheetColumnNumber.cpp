/* 
 * Author: cc
 * Date  : 2015-02-19
 * Source: https://oj.leetcode.com/problems/excel-sheet-column-number/
 * Description:
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *
 *     A -> 1
 *      B -> 2
 *      C -> 3
 *      ...
 *      Z -> 26
 *      AA -> 27
 *      AB -> 28 
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

int titleToNumber(string s) {
    int res = 0;
   

    for (int i = 0; i < s.length(); ++i)
    {
        res = res * 26 + s[i] - 'A' + 1; 
    }
    return res;
}

int main(int argc, char *argv[]) {

    cout<<"res is "<<titleToNumber("AB");
    return 0;
}


/* 
 * Author: cc
 * Date  : 2015-05-23
 * Source: https://leetcode.com/problems/zigzag-conversion/
 * Description:
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:

 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

string convert(string s, int numRows) { 
    string res;
    int len = s.size();

    if (len <= 1 || numRows == 1) {
        return s;
    }
    for (int i = 0; i < numRows; ++i) {
        int deta = 0;
        int deta1 = 0;
        int j = i;
        if (i == 0 || i == numRows - 1) {
            deta =  deta1 = 2 * numRows - 2;
        }else {
            deta = 2 * (numRows - i) - 2;
            deta1 = 2 *i;
        }
        
        int deta_flag = 0;
        while(j < len)
        {
            cout<<j<<endl;
            cout<<s[j]<<endl;
            res.push_back(s[j]);
            if (deta_flag) {
                j += deta1;
                deta_flag = 0;
            }else{
                j += deta;
                deta_flag = 1;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    cout<<convert("ABCDEF", 5)<<endl;
    cout<<convert("PAYPALISHIRING", 3)<<endl;
    return 0;
}


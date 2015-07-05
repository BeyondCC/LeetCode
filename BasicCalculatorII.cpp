/* 
 * Author: cc
 * Date  : 2015-07-04
 * Source: https://leetcode.com/problems/basic-calculator-ii/
 * Description:
 * Implement a basic calculator to evaluate a simple expression string.

 The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

 You may assume that the given expression is always valid.

 Some examples:
 "3+2*2" = 7
 " 3/2 " = 1
 " 3+5 / 2 " = 5

 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<sstream>
using namespace std;

// if encounter + or - , use the res to add the pre num(with sign)
// if encounter * or / , get next number and replace the current num with the res of two number
//http://bookshadow.com/weblog/2015/06/23/leetcode-basic-calculator-ii/
int calculate(string s) {
    //istringstream split the string with space character
    istringstream in(s + "+");
    long long total = 0, term, sign = 1, n;
    in >> term;
    char op;
    while (in >> op) {
        if (op == '+' || op == '-') {
            total += sign * term;
            sign = 44 - op; //op == '+' ? 1 : -1
            in >> term;
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}

int main(int argc, char *argv[]) {
    cout<<"res is "<<calculate("1+1-1")<<endl;
    return 0;
}


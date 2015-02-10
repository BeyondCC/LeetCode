/* 
 * Author: cc
 * Date  : 2015-02-10
 * Source: https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
 * Description:
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 *  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool isOperator(string s) {

    bool res = false;

    if (s == "+" || s == "-" || s == "*" || s == "/")
    {
        res = true;
    }

    return res;
}

//波兰表达式
int evalRPN(vector<string> &tokens) {
    
    stack<int> operands;
    stack<string> operators;

    for (int i = 0; i < tokens.size(); ++i)
    {
        if (isOperator(tokens[i]))
        {
            if (operands.size() >= 2)
            {
                int right = operands.top();
                operands.pop();

                int left = operands.top();
                operands.pop();

                if (tokens[i] == "+")
                {
                    int result = left + right;

                    operands.push(result);
                }else if (tokens[i] == "-") {
                    int result = left - right;

                    operands.push(result);
                }else if (tokens[i] == "*") {
                    int result = left * right;

                    operands.push(result);
                }else if (tokens[i] == "/") {
                    int result = left / right;

                    operands.push(result);
                }
            }else{
                return 0;
            }
        }else{
            operands.push(stoi(tokens[i]));
        }
    }

    int res = operands.top();

    return res;
}

int main(int argc, char *argv[]) {
    
    vector<string> v;

    v.push_back("2");
    v.push_back("1");
    v.push_back("+");
    v.push_back("3");
    v.push_back("*");


    cout<<evalRPN(v)<<endl;

    return 0;
}


/* 
 * Author: cc
 * Date  : 2015-06-09
 * Source: https://leetcode.com/problems/basic-calculator/ 
 * Description:
 * Implement a basic calculator to evaluate a simple expression string.

 The expression string may contain open ( and closing parentheses  ), the plus + or minus sign -, non-negative integers and empty spaces .

 You may assume that the given expression is always valid.

 Some examples:
 "1 + 1" = 2
 " 2-1 + 2 " = 3
 "(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool isOp(char c)
{
    if (c == '+' || c == '-' || c == '(' || c == ')') {
        return true;
    }    

    return false;
}

bool isOperand(char c)
{
    if ( '0' <= c && c <= '9' ) {
        return true;
    }
        
    return false;
}

int calculate(string s) {
    stack<char> op;
    stack<int> operand;
    bool flag = false;
    int end = 0;
    int start = 0;

    for (int i = 0; i < s.size(); ++i) {
        cout<<"size:"<<operand.size()<<endl;
        cout<<"op size:"<<op.size()<<endl;
        if (s[i] == ' ') {
            continue;
        }

        if (!flag) {
           start = i;
        }else{
            end = i;
        }

        if (isOperand(s[i])) {
            flag = true;
        }else if (isOp(s[i])) {
            if (flag) {
                string str = s.substr(start, end - start + 1); 
                int num = atoi(str.c_str());
                cout<<"pre num:"<<num<<endl;
                operand.push(num);
    
                if (operand.size() > 1) {
                    if (op.top() != '(' && op.top() != ')') {
                        int right = operand.top();
                        operand.pop();
                        int left = operand.top();
                        operand.pop();

                        if (op.top() == '+') {
                            operand.push(left + right);
                        }else{
                            operand.push(left - right);
                        }
                        cout<<left<<" "<<op.top()<<right<<" = "<<operand.top()<<endl;
                        op.pop();
                        
                    }                    
                }
            }

            if (s[i] == ')') {
                while(op.top() != '(')
                {
                    if (operand.size() > 1) {
                        int right = operand.top();
                        operand.pop();
                        int left = operand.top();
                        operand.pop();

                        if (op.top() == '+') {
                            operand.push(left + right);
                        }else{
                            operand.push(left - right);
                        }
                        cout<<left<<" "<<op.top()<<right<<" = "<<operand.top()<<endl;
                        op.pop();
                    }
                }
                op.pop();
            }else if(s[i] == '('){
                op.push(s[i]);
            }else{
                if (operand.size() > 1) {
                    if (op.top() != '(' && op.top() != ')') {
                        int right = operand.top();
                        operand.pop();
                        int left = operand.top();
                        operand.pop();

                        if (op.top() == '+') {
                            operand.push(left + right);
                        }else{
                            operand.push(left - right);
                        }
                        cout<<left<<" "<<op.top()<<right<<" = "<<operand.top()<<endl;
                        op.pop();
                        
                    }                    
                }
                op.push(s[i]);
            }

            flag = false;
        }
    }
    
    if (flag) {
        end = end > start ? end : s.size() - 1;
        string str = s.substr(start, end - start + 1);
        int num = atoi(str.c_str());
        cout<<"final num:"<<num<<endl;
        operand.push(num);
    }

    while(op.size() != 0 )
    {
        if (operand.size() > 0) {
            int right = operand.top();
            operand.pop();
            int left = operand.top();
            operand.pop();

            if (op.top() == '+') {
                operand.push(left + right);
            }else{
                operand.push(left - right);
            }
            cout<<left<<" "<<op.top()<<right<<" = "<<operand.top()<<endl;
        }
            
        op.pop();     
    }

    return operand.top();
}

int main(int argc, char *argv[]) {
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout<<calculate(s)<<endl;
    return 0;
}


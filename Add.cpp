/* 
 * Author: cc
 * Date  : 2015-08-26
 * Source:  http://www.nowcoder.com/books/coding-interviews/59ac416b4b944300b617d4f7f111b215?rp=2
 * Description:
 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int carry = 0;
        int sum = 0;
        
        do{
            sum = (num1 ^ num2);    // 两个数的和不带进位
            carry = (num1 & num2) << 1; //两个数和的进位
            num1 = sum;
            num2 = carry;
        }while(carry != 0); // 当不产生进位的时候得到结果
        
        return sum;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}


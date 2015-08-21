/* 
 * Author: cc
 * Date  : 2015-08-21
 * Source: http://www.nowcoder.com/books/coding-interviews/22243d016f6b47f2a6928b4313c85387?rp=1
 * Description:
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
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
    int jumpFloorII(int number) {
    if(number <= 1)
            return 1;
        int* tmp = new int[number];
        tmp[0] = 1;
        tmp[1] = 2;
        for(int i = 2; i < number; i++)
        {
//加上n-1, n-2,n-3的跳法
            for(int j = i - 1; j >= 0; j--)
                tmp[i] += tmp[j];
//跳n步
            tmp[i] += 1;
        }
        return tmp[number-1];
    }
};




int main(int argc, char *argv[]) {
    return 0;
}


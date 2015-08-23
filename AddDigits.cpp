/* 
 * Author: cc
 * Date  : 2015-08-23
 * Source: https://leetcode.com/problems/add-digits/
 * Description:
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

 For example:

 Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
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
        //可以找到规律，最终的结果为0,1,2,3,4,...9,,1....9.1....9,1.....9
        //对于非0的数对9取余即可
        int addDigits(int num) {
            if(num == 0) {
                return 0;
            }
            int res = num % 9;
            return  res == 0 ? 9 : res;
        }

};

int main(int argc, char *argv[]) {
    return 0;
}


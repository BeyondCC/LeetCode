/* 
 * Author: cc
 * Date  : 2015-08-23
 * Source: https://leetcode.com/problems/ugly-number/
 * Description:
 * Write a program to check whether a given number is an ugly number.

 Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

 Note that 1 is typically treated as an ugly number.
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
        bool isUgly(int num) {
            int a[] = {2, 3, 5};

            while(num) {
                if (num == 1) {
                    return true;
                }
                int i = 0;
                for (i = 0; i < 3; ++i) {
                    if (num % a[i] == 0) {
                        num = num / a[i];
                        break;
                    }
                }

                if (i >= 3) {
                    return false;
                }
            }

            return false;
        }

};

int main(int argc, char *argv[]) {
    Solution s;

    cout<<s.isUgly(7)<<endl;
    return 0;
}


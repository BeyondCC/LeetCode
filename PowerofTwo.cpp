/* 
 * Author: cc
 * Date  : 2015-08-04
 * Source: https://leetcode.com/problems/power-of-two/
 * Description:
 * Given an integer, write a function to determine if it is a power of two.
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
        bool isPowerOfTwo(int n) {
            int count = 0;

            if (n == INT_MIN) { 
                return false;
            }

            while(n) {
                //count the count of 1 which n has
                n = n & (n - 1);
                count++;
            }

            if (count == 1) {
                return true;
            }

            return false;
        }

};

int main(int argc, char *argv[]) {
    Solution s;

    cout<<s.isPowerOfTwo(4)<<endl;
    cout<<s.isPowerOfTwo(31)<<endl;
    cout<<s.isPowerOfTwo(-2147483648)<<endl;
    
    return 0;
}


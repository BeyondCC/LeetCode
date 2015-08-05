/* 
 * Author: cc
 * Date  : 2015-06-17
 * Source: https://leetcode.com/problems/bitwise-and-of-numbers-range/
 * Description:
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

 For example, given the range [5, 7], you should return 4.
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
    int rangeBitwiseAnd(int m, int n) {
        if(m == n)
            return m;

        int count = m & n;
        int res = m;

        int bit =m;
        bit = bit<<1;

        //if bit < n and bit > m, so all the bits is zero
        if (bit < n  && bit > m ) {
            return 0;
        }

        //to resolve the tle problem
        if (bit >= n ) {
            for (int i = m + 1; i <= n; ++i) {
                 res &= i;
            }

            return res;
        }

        for (int i = m + 1; i <= n && i <= m + count; ++i) {
            res &= i;
        }

        return res;
        
    }
};


int main(int argc, char *argv[]) {
    cout<<rangeBitwiseAnd(3,4)<<endl;
    return 0;
}


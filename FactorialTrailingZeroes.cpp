/* 
 * Author: cc
 * Date  : 2015-05-20
 * Source: https://leetcode.com/problems/factorial-trailing-zeroes/
 * Description:
 * Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

// to get the number of 5 in 0 to range n
// count is floor(n / 5) + floort(n / 25) ....
int trailingZeroes(int n) {
    long x = 5;
    int count = 0;

    while(n >= x)
    {
        count += n / x;
        x *= 5;
    }

    return count;
}

int main(int argc, char *argv[]) {
    return 0;
}


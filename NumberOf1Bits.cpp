/* 
 * Author: cc
 * Date  : 2015-04-05
 * Source: https://leetcode.com/problems/number-of-1-bits/ 
 * Description:
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

int hammingWeight(uint32_t n) {
    
    int count = 0;

    while(n)
    {
        n = (n - 1) & n;
        count++;
    }

    return count;
}

int main(int argc, char *argv[]) {
    cout<<hammingWeight(4)<<endl;
    return 0;
}


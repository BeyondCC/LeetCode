/* 
 * Author: cc
 * Date  : 2015-04-06
 * Source: https://leetcode.com/problems/reverse-bits/
 * Description:
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 * Related problem: Reverse Integer
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;

    for (int i = 0; i < 32; ++i)
    {
        int low = n & 1;
        
        res = res | low << (31 - i);

         n >>= 1;
    }
    
    return res;
}

int main(int argc, char *argv[]) {
    int i = 1;

    cout<<reverseBits(43261596)<<endl;

    return 0;
}


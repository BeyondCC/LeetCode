/* 
 * Author: cc
 * Date  : 2015-09-08
 * Source: https://leetcode.com/problems/gray-code/
 * Description:
 * The gray code is a binary numeral system where two successive values differ in only one bit.

 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

 00 - 0
 01 - 1
 11 - 3
 10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
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
        //对于格雷码：二进制码转换成格雷码
        // grayCode: binary ^ (binary >> 1)
        vector<int> grayCode(int n) {
            int num = 1 << n;
            vector<int> res;

            res.reserve(num);

            for (int i = 0; i < num; ++i) {
                res.push_back(i ^ (i >> 1)); 
            }

            for (int i = 0; i < res.size(); ++i) {
                cout<<res[i]<<endl; 
            }
            return res;
        }

};

int main(int argc, char *argv[]) {
    Solution s;
    s.grayCode(2);
    return 0;
}


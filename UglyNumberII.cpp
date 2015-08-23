/* 
 * Author: cc
 * Date  : 2015-08-23
 * Source: https://leetcode.com/problems/ugly-number-ii/
 * Description:
 * Write a program to find the n-th ugly number.

 Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

 Note that 1 is typically treated as an ugly number.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        int nthUglyNumber(int n) {
            vector<int> buf;
            int index2 = 0;
            int index3 = 0;
            int index5 = 0;
            int res = 1;

            while(--n)
            {
                buf.push_back(res);

                int v2 = 2 * buf[index2];
                int v3 = 3 * buf[index3];
                int v5 = 5 * buf[index5];

                res = min(v2, min(v3, v5));

                //更新对应的索引位置
                index2 += (res == v2);
                index3 += (res == v3);
                index5 += (res == v5);
            }

            return res;
        }

};

int main(int argc, char *argv[]) {
    Solution s;

    cout<<s.nthUglyNumber(1)<<endl;
    for (int i = 1; i < 10; ++i) {
        cout<<s.nthUglyNumber(i)<<endl;
    }
    return 0;
}


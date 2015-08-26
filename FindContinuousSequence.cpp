/* 
 * Author: cc
 * Date  : 2015-08-26
 * Source: http://www.nowcoder.com/books/coding-interviews/c451a3fd84b64cb19485dad758a55ebe?rp=2
 * Description:
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
        //维持两个边界，当总和大于sum，左边界右移，小于sum，右边界右移
        vector<vector<int> > FindContinuousSequence(int sum) {
            vector<vector<int> > res;
            if (sum <= 2) {
                return res;
            }

            int left = 1, right = 2, totalSum = 3;

            while(left < right && right < sum) {
                if (totalSum == sum) {
                    vector<int> v;
                    for (int i = left; i <= right; ++i) {
                        v.push_back(i);
                    }

                    res.push_back(v);
                    totalSum -= left;
                    left++;
                }else if(totalSum < sum) {
                    right++;
                    totalSum += right;
                }else{
                    totalSum -= left;
                    left++;
                }
            }

            return  res;
        }

};

int main(int argc, char *argv[]) {
    return 0;
}


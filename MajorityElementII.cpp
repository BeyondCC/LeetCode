/* 
 * Author: cc
 * Date  : 2015-09-05
 * Source: https://leetcode.com/problems/majority-element-ii/
 * Description:
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
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
        vector<int> majorityElement(vector<int>& nums) {
            vector<int> res;

            int candidate1 = 0, candidate2 = 0;
            int count1 = 0, count2 = 0;
            bool flag1 = false, flag2 = false;

            for (int i = 0; i < nums.size(); ++i) {
                 if (count1 == 0) {
                    candidate1 = nums[i];
                    count1++;
                    flag1 = true;
                }else if (candidate1 == nums[i]) {
                    count1++;
                }else if (count2 == 0) {
                    candidate2 = nums[i];
                    count2++;
                    flag2 = true;
                }else if (candidate2 == nums[i]) {
                    count2++; 
                }else{
                    count1--;
                    count2--;
                }
            }

            count1 = 0;

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == candidate1) {
                    count1 += 2;
                }else{
                    count1--;
                }

                if (nums[i] == candidate2) {
                    count2 += 2;
                }else{
                    count2--;
                }
            }

            if (count1 > 0) {
                res.push_back(candidate1);
            }

            if (count2 > 0) {
                res.push_back(candidate2);
            }
            for (int i = 0; i < res.size(); ++i) {
                cout<<res[i]<<endl; 
            }
            return res;
        }

};

int main(int argc, char *argv[]) {
    int a[] = {2, 2, 1, 3};

    vector<int> v(a, a + 4);
    Solution s;

    s.majorityElement(v);
    return 0;
}


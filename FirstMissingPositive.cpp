/* 
 * Author: cc
 * Date  : 2015-09-04
 * Source:  https://leetcode.com/problems/first-missing-positive/
 * Description:
 * Given an unsorted integer array, find the first missing positive integer.

 For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.

 Your algorithm should run in O(n) time and uses constant space.
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
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        
        // 第i位存放i+1, 整个数组存放1 到 size
        // 如果nums[i] 在1到size之间并且不等于i+1,将其放到nums[nums[i] - 1]
        while (i < size) {
            if (nums[i] != (i + 1) && nums[i] >= 1 && nums[i] <= size && nums[nums[i] - 1] != nums[i] ) {
                swap(nums[i], nums[nums[i] - 1]);
            }else{
                i++;
            }
        } 

        for (int i = 0; i < size; ++i) {
            if (nums[i] != (i + 1)) {
                return i + 1;
            } 
        }

        return size + 1;
    }        
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(1);

    cout<<s.firstMissingPositive(nums)<<endl;
    return 0;
}


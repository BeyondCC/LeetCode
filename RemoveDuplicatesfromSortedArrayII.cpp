/* 
 * Author: cc
 * Date  : 2015-09-06
 * Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * Description:
 * Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?

 For example,
 Given sorted array nums = [1,1,1,2,2,3],

 Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
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
        int removeDuplicates(vector<int>& nums) {
            int length = 0;
            if (nums.size() == 0) {
                return length; 
            }

            int pre = nums[0];
            int count = 1; 
            length++;

            //记录当前应该放置元素的位置
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] == pre && count < 2) {
                    nums[length] = nums[i];
                    length++;
                    count++;
                }else if(nums[i] != pre) {
                    nums[length] = nums[i];
                    length++;
                    count = 1;
                }

                pre = nums[i];
            }

            return length;
        }

};

int main(int argc, char *argv[]) {
    int a[] = {1,1,1,1,1,1};
    vector<int> nums(a, a + 6);

    Solution s;

    cout<<s.removeDuplicates(nums)<<endl;
    return 0;
}


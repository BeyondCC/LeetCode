/* 
 * Author: cc
 * Date  : 2015-08-17
 * Source: https://leetcode.com/problems/subsets-ii/
 * Description:
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
    [1],
      [1,2,2],
        [2,2],
          [1,2],
            []

]
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
        vector<vector<int> > subsetsWithDup(vector<int>& nums) {
            vector<vector<int> > res;
            vector<int> tmp;
            
            if (nums.empty()) {
                return res;
            }

            sort(nums.begin(), nums.end());
            helper(nums, 0, tmp, res);

            for (int i = 0; i < res.size(); ++i) {
                for (int j = 0;  j < res[i].size() ; j++) {
                    cout<<res[i][j]<<" ";
                }
                cout<<endl;
            }
            return res;
        }

        void helper(vector<int> nums, int begin, vector<int> &tmp, vector<vector<int> > &res) {
            if (begin > nums.size()) {
                return;
            }
            res.push_back(tmp);
            for (int i = begin; i < nums.size(); ++i) {
                //列举所有情况，然后回溯
                if (i > begin && nums[i] == nums[i - 1]) {
                    continue;
                }
                tmp.push_back(nums[i]);
                helper(nums, i + 1, tmp, res);
                tmp.pop_back();
            }
            
        }
};

int main(int argc, char *argv[]) {
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);

    Solution s;
    s.subsetsWithDup(nums);
    return 0;
}


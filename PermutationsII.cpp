/* 
 * Author: cc
 * Date  : 2015-08-16
 * Source: https://leetcode.com/problems/permutations-ii/
 * Description:
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.

 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        vector<vector<int> > permute(vector<int>& nums) {
            vector<vector<int> > res;
            vector<int> tmp;

            sort(nums.begin(), nums.end());
            vector<bool> used(nums.size(), false);
            helper(nums, used, tmp, res);

            return res;
        }

        void helper(vector<int> &nums, vector<bool> &used, vector<int> &tmp, vector<vector<int> > &res) {
            if (tmp.size() == nums.size()) {
                res.push_back(tmp);
                return;
            }

            for (int i = 0; i < nums.size(); ++i) {
                //如果当前元素跟之前的元素相等，并且之前未被使用，则不进行递归(之前的元素未被使用证明是已经递归然后重置)
                if (i > 0 && !used[i - 1] && nums[i - 1] == nums[i]) {
                    continue;
                }
                if (!used[i]) {
                    used[i] = true;
                    tmp.push_back(nums[i]);
                    helper(nums, used, tmp, res);
                    tmp.pop_back();
                    used[i] = false;
                }    
            }
        }
};

int main(int argc, char *argv[]) {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(3);

    Solution s;
    vector<vector<int> > permutes = s.permute(nums);

    for (int i = 0; i < permutes.size(); ++i) {
        vector<int> row = permutes[i];
        for (int j = 0; j < row.size(); ++j) {
            cout<<row[j]<<" "; 
        }

        cout<<endl;
    }
    return 0;
}


/* 
 * Author: cc
 * Date  : 2015-08-16
 * Source: https://leetcode.com/problems/permutations/
 * Description:
 *  Given a collection of numbers, return all possible permutations.

 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
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
            set<vector<int> > set_res;
            vector<vector<int> > res;
            vector<int> tmp;
            vector<bool> used(nums.size(), false);
           // helper(nums, 0, set_res);
            helper2(nums, used, tmp, res);

            return res;
        }

        //brute-force to get the answer
        void helper2(vector<int> &nums, vector<bool> &used, vector<int> &tmp, vector<vector<int> > &res) {
            if (tmp.size() == nums.size()) {
                res.push_back(tmp);
                return;
            }

            for (int i = 0; i < nums.size(); ++i) {
                if (!used[i]) {
                    used[i] = true;
                    tmp.push_back(nums[i]);
                    helper2(nums, used, tmp, res);
                    tmp.pop_back();
                    used[i] = false;
                }    
            }
        }

        void swap(vector<int> &nums, int i, int j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }

        void helper(vector<int> &nums, int start, set<vector<int> > &res) {
            if (start == nums.size()) {
                res.insert(nums);
                return;
            }    

            for (int i = start; i < nums.size(); ++i) {
                for (int j = i; j < nums.size(); ++j) {
                    swap(nums, i, j);
                    helper(nums, start + 1, res);
                    swap(nums, i, j);
                }
            }
        }

};

int main(int argc, char *argv[]) {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
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


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

            res.push_back(tmp);
            sort(nums.begin(), nums.end());
        
            for (int i = 0; i < nums.size(); ++i) {
                vector<vector<int> > tmpRes;
                for (int j = 0; j < res.size(); ++j) {
                    vector<int> tmp = res[j];
                    tmp.push_back(nums[i]);
                    tmpRes.push_back(tmp);
                }

                for (int i = 0; i < tmpRes.size(); ++i) {
                    res.push_back(tmpRes[i]);
                }
            }

            for (int i = 0; i < res.size(); ++i) {
                vector<int> row = res[i];

                for (int j = 0; j < row.size(); ++j) {
                    cout<<row[j]<<" ";
                }

                cout<<endl;
            }

            return res;
        }
};

int main(int argc, char *argv[]) {
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    Solution s;
    s.subsetsWithDup(nums);
    return 0;
}


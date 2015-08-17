/* 
 * Author: cc
 * Date  : 2015-08-17
 * Source: https://leetcode.com/problems/combination-sum-ii/
 * Description:
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

 Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
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
        vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int> > res;
            vector<int> tmp;
            vector<bool> used(candidates.size(), false);
            sort(candidates.begin(), candidates.end());
            
            helper(candidates, 0, tmp, res, target);

            return res;
        }

        void helper(vector<int> candidates, int start, vector<int> &tmp, vector<vector<int> > &res, int target) {
            if (target < 0) {
                return;
            }

            if (target == 0) {
                res.push_back(tmp);
            }

            for (int i = start; i < candidates.size(); ++i) {
                //每个元素只能使用一次，当前元素和前一个元素相同并且前一个元素调用时continue
                if (i > start  && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                tmp.push_back(candidates[i]);
                helper(candidates, i + 1, tmp, res, target - candidates[i]);
                tmp.pop_back();
            }
        }

};

int main(int argc, char *argv[]) {
    vector<int> candidates;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);

    Solution s;
    vector<vector<int> > res = s.combinationSum2(candidates, 8);

    for (int i = 0; i < res.size(); ++i) {
        vector<int> row = res[i];

        for (int j = 0; j < row.size(); ++j) {
            cout<<row[j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}


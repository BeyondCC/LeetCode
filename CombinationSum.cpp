/* 
 * Author: cc
 * Date  : 2015-08-16
 * Source: https://leetcode.com/problems/combination-sum/ 
 * Description:
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

 The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
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
        vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
            vector<vector<int> >res;
            vector<int> tmp;

            if (candidates.empty()) {
                return res;
            }
            
            sort(candidates.begin(), candidates.end());
            helper(candidates, 0, target, tmp, res);

            return res;
        }

        void helper(vector<int> candidates, int start, int target, vector<int> &tmp, vector<vector<int> > & res) {
            if (target < 0) {
                return;
            }

            if (target == 0) {
                res.push_back(tmp);
            }

            for (int i = start; i < candidates.size(); ++i) {
                tmp.push_back(candidates[i]);
                helper(candidates, i, target - candidates[i], tmp, res);
                tmp.pop_back();
            }
        }
};

int main(int argc, char *argv[]) {
    vector<int> candidates;
    candidates.push_back(8);
    candidates.push_back(7);
    candidates.push_back(4);
    candidates.push_back(3);

    Solution s;

    vector<vector<int> > res = s.combinationSum(candidates, 11);

    for (int i = 0; i < res.size(); ++i) {
        vector<int> tmp = res[i];

        for (int j = 0;  j < tmp.size(); j++) {
            cout<<tmp[j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}


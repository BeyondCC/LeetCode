/* 
 * Author: cc
 * Date  : 2015-08-17
 * Source: https://leetcode.com/problems/combination-sum-iii
 * Description:
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

 Ensure that numbers within the set are sorted in ascending order.


 Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
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
        vector<vector<int> > combinationSum3(int k, int n) {
            vector<vector<int> > res;
            vector<int> tmp;

            helper(1, k, n, tmp, res);

            return res;
        }

        void helper(int begin, int remain, int target, vector<int> &tmp, vector<vector<int> > &res) {
            if (remain < 0 || target < 0) {
                return;
            }

            if (remain == 0 && target == 0) {
                res.push_back(tmp);
                return;
            }

            for (int i = begin; i <= 9; ++i) {
                tmp.push_back(i);
                helper(i + 1, remain - 1, target - i, tmp, res);
                tmp.pop_back();
            }
        }

};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int> > res = s.combinationSum3(3, 9);

    for (int i = 0; i < res.size(); ++i) {
        vector<int> row = res[i];

        for (int j = 0; j < row.size(); ++j) {
            cout<<row[j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}


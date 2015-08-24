/* 
 * Author: cc
 * Date  : 2015-02--15
 * Source: https://oj.leetcode.com/problems/combinations/
 * Description:
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

void helper(int start, int n, int k, vector<int> &tmp, vector<vector<int> > &res);

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > res;
    vector<int> tmp;

    if (n < k) {
        return res;
    }

    helper(1, n, k, tmp, res);

    for (int i = 0; i < res.size(); ++i) {
        vector<int> row = res[i];

        for (int j = 0; j < row.size(); ++j) {
            cout<<row[j]<<" ";
        }

        cout<<endl;
    }
    return res;
}

void helper(int start, int n, int k, vector<int> &tmp, vector<vector<int> > &res){
    if (start > n && k > 0) {
        return;
    }
    if (k == 0) {
         res.push_back(tmp);
    } 
    
    for (int i = start; i <= n; ++i) {
        tmp.push_back(i);
        helper(i + 1, n, k - 1, tmp, res);
        //回溯
        tmp.pop_back();
    }
}

int main(int argc, char *argv[]) {
    combine(4, 3);
    return 0;
}


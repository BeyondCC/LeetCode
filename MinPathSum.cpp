/*
 * Source: https://oj.leetcode.com/problems/minimum-path-sum/
 * Description: Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 */

#include<iostream>
#include<vector>

using namespace std;

int minPathSum(vector<vector<int> > &grid) {
    int res = 0;

    int size = grid.size();
    
    if(size == 0)
        return res;

    size = grid[0].size();

    int *dp = new int[size];
    for(int i = 0; i < size; i++)
        dp[i] = 0;

    dp[0] = grid[0][0];

    for(int i = 0; i < grid.size(); i++)
    {
        vector<int> row = grid[i];

        for(int j = 0; j < row.size(); j++)
        {
            cout<<"row["<<j<<"]:"<<row[j]<<endl;
            if(i == 0 && j == 0){
                dp[i] = row[i];
                continue;
            }
            if(i == 0)
            {
                dp[j] = row[j] + dp[j - 1];
            }else if(j == 0){
                dp[j] = dp[j] + row[j];
            }else{
                if(dp[j - 1] > dp[j])
                {
                    dp[j] = dp[j] + row[j];
                }else{
                    dp[j] = dp[j - 1] + row[j];
                }
            }
        }
    }

    return dp[size - 1];
}

int main(int argc, char *argv[]) {
    vector<vector<int> > v;

    for(int i = 0; i < 6; i++){
        vector<int> row;
        row.push_back(1);
        row.push_back(1);
        row.push_back(1);
        row.push_back(1);
        row.push_back(1);

        v.push_back(row);
    }
    cout<<minPathSum(v)<<endl;
    return 0;
}

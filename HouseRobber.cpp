/* 
 * Author: cc
 * Date  : 2015-05-23
 * Source: https://leetcode.com/problems/house-robber/
 * Description:
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

 Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

/*
 * dp[i] stands for the max money while the robber reach the ith house
 * flag[i] stands for whether stole the ith house to get the max money, 1 stands for yes
 * time :O(n)
 */
int rob(vector<int>& nums) {
    int *dp = (int *)malloc(sizeof(int) * nums.size());
    int *flag = (int *)malloc(sizeof(int) * nums.size());
    int res = 0;
    int local = 0;
  
    if (nums.size() == 1) {
        return nums[0]; 
    }

    if (nums.size() == 2) {
        res = max(nums[0], nums[1]);
        return res;
    }

    dp[0] = nums[0];
    flag[0] = 1;
    
    if (nums[0] >= nums[1]) {
        dp[1] = nums[0];
        flag[1] = 0;
    }else{
        dp[1] = nums[1];
        flag[1] = 1;
    }
    for (int i = 2; i < nums.size(); ++i) {
        if (!flag[i - 1]) {
            dp[i] = max(dp[i - 1] + nums[i], dp[i - 2] + nums[i]);
            flag[i] = 1;
        }else{
            if (dp[i - 1] >= dp[i - 2] + nums[i]) {
                dp[i] = dp[i - 1];
                flag[i] = 0;
            }else{
                dp[i] = dp[i - 2] + nums[i];
                flag[i] = 1;
            }
        }
        cout<<dp[i]<<endl;
        res = max(res, dp[i]);
    }            

    return res;
}

int main(int argc, char *argv[]) {
    vector<int> v;

    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    cout<<rob(v)<<endl;
    return 0;
}


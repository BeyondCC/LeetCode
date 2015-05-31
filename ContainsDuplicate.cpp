/* 
 * Author: cc
 * Date  : 2015-05-31
 * Source: https://leetcode.com/problems/contains-duplicate/
 * Description:
 * Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

//or use hashset O(n)
bool containsDuplicate(vector<int>& nums) {
    if (nums.size() <= 1) {
        return false;
    }

    sort(nums.begin(), nums.end());

    int pre = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == pre) {
            return true;
        }

        pre = nums[i];
    }
    
    return false;
}
        
int main(int argc, char *argv[]) {
    vector<int> nums;
    
    nums.push_back(10);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);

    cout<<containsDuplicate(nums)<<endl;
    return 0;
}


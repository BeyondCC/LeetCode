/* 
 * Author: cc
 * Date  : 2015-05-31
 * Source: https://leetcode.com/problems/contains-duplicate-ii/
 * Description:
 * Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> dict;

    for (int i = 0; i < nums.size(); ++i) {
       if (dict.find(nums[i]) == dict.end()) {
          dict.insert(make_pair(nums[i], i)); 
       } else{
           int preIndex = dict[nums[i]];

           if (i - preIndex <= k) {
               return true;
           }

           dict[nums[i]] = i;
       }
    }

    return false;
}

int main(int argc, char *argv[]) {
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(1);

    cout<<containsNearbyDuplicate(nums, 2)<<endl;
    return 0;
}


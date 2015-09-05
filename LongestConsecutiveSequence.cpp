/* 
 * Author: cc
 * Date  : 2015-09-04
 * Source: https://leetcode.com/problems/longest-consecutive-sequence/
 * Description:
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

 Your algorithm should run in O(n) complexity.
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
        //可以理解为排序O(n), 只能利用空间换取时间，每个数取出来在字典中增序、降序进行计算长度
        int longestConsecutive(vector<int>& nums) {
            unordered_map<int, int> dict;
            int count = 0;
            int res = 0;

            for (int i = 0; i < nums.size(); ++i) {
                if (dict.find(nums[i]) == dict.end()) {
                    dict.insert(make_pair(nums[i], 1));
                } 
            }
            
            for (int i = 0; i < nums.size(); ++i) {
                int j = i + 1;
                int num = nums[i];
                int ascNum = num + 1;
                int descNum = num - 1;
                while(dict.find(ascNum) != dict.end()) {
                    dict.erase(ascNum);

                    count++;
                    ascNum++;
                }

                while(dict.find(descNum) != dict.end()) {
                    dict.erase(descNum);

                    descNum--;
                    count++;
                }

                count = count + 1;
                if (count > res) {
                    res = count;
                }

                count = 0;
            }

            return res;
    }

};

int main(int argc, char *argv[]) {
    vector<int> nums;

    nums.push_back(100);
    nums.push_back(4);
    nums.push_back(200);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);

    Solution s;
    cout<<s.longestConsecutive(nums)<<endl;

    return 0;
}


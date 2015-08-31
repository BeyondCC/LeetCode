/* 
 * Author: cc
 * Date  : 2015-08-31
 * Source: https://leetcode.com/problems/kth-largest-element-in-an-array/
 * Description:
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

 For example,
 Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
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
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0, end = nums.size() - 1;
        k = k - 1;
        while(start <= end) {
            int pos = partion(nums, start, end);

            if (pos == k) {
                return nums[pos];
            }else if(pos > k) {
                end = pos -1;
            }else {
                start = pos + 1;
            }
        }

        return -1;
    }


    int partion(vector<int> &nums, int start, int end) {
        int key = nums[end];
        int pos = start -1;

        for (int i = start; i < end; ++i) {
            if (nums[i] > key) {
                swap(nums, ++pos, i);
            }
        }

        swap(nums, ++pos, end);
        
        cout<<"pos:"<<pos<<endl;
        return pos;
    }

    void swap(vector<int> &nums, int pos1, int pos2) {
        int tmp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = tmp;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums;

    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);


    Solution s;

    for (int i = 1; i < 5; ++i) {
        cout<<s.findKthLargest(nums, i)<<endl;
    }

    return 0;
}


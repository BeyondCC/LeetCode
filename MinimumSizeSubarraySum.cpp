/* 
 * Author: cc
 * Date  : 2015-09-05
 * Source: https://leetcode.com/problems/minimum-size-subarray-sum/
 * Description:
 * Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

 For example, given the array [2,3,1,2,4,3] and s = 7,
 the subarray [4,3] has the minimal length under the problem constraint.
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
        //正整数一直相加直至超过s，index移至下一位判断当前和是否超过s，若超过更新res下一位，否则一直相加直至超过s
        //左右边界确定最短的连续和
        int minSubArrayLen(int s, vector<int>& nums) {
            int sum = 0;
            int length = 0;
            int pre = 0;
            int res = 0;
            int i = 0;

            while (i < nums.size()) {
                sum -= pre;
                cout<<"pre:"<<sum<<endl;
                int j = i + length;
                cout<<i<<" "<<j<<" ";

                if (sum >= s) {
                    if (res == 0) {
                        res = length;
                    }else{
                        res = min(res, length);
                    }
                    pre = nums[i];
                    i++;
                    length--;
                    continue;
                }
                for (; j < nums.size(); ++j) {
                    sum += nums[j];
                    length++;

                    if (sum >= s) {
                        if (res == 0) {
                            res = length; 
                        }else{
                            res = min(res, length);
                        }
                        break;
                    }
                }
                
                pre = nums[i]; 

                cout<<sum<<endl;
                if (j >= nums.size()) {
                    if (sum <  s) {
                        break; 
                    }
                    length = 0; 
                    i++;
                }else{
                    length--;
                    i++;
                }

                
            }

            return res;
        }
        
        int minSubArrayLen2(int s, vector<int>& nums) {
            vector<int> sum(nums.size() + 1, 0);
            int res = INT_MAX;

            for (int i = 0; i < nums.size(); ++i) {
                sum[i + 1] = sum[i] + nums[i];

                if (sum[i + 1] >= s) {
                    int index =  find(sum, sum[i + 1] - s + 1, 0, i);

                    if (index > -1 ) {
                        res = min(res, i - index + 1);
                    }
                }
            }

            return res == INT_MAX ? 0 : res;
        }

        int find(vector<int> sum, int target, int start, int end) {

            while(start < end - 1) {
                int middle = start + (end - start) / 2;
                
                if (sum[middle] >= target) {
                    end = middle -1;
                }else{
                    start = middle;
                }
            }

            if (sum[end] < target) {
                return end;
            }else if(sum[start] < target) {
                return start;
            }else
                return -1;

        }
};

int main(int argc, char *argv[]) {
    int a[] = {2,3,1,2,4,3};
    
    vector<int> nums(a, a + 6);
    Solution s;

    cout<<s.minSubArrayLen2(0, nums)<<endl;

    return 0;
}


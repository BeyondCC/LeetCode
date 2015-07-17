/* 
 * Author: cc
 * Date  : 2015-07-17
 * Source: https://leetcode.com/problems/product-of-array-except-self/
 * Description:
 * Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

 Solve it without division and in O(n).

 For example, given [1,2,3,4], return [24,12,8,6].


 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> num_pre_product;
    vector<int> num_post_product;
    vector<int> res;

    for (int i = 0; i < nums.size(); ++i) {
        int product = i == 0 ? 1 : num_pre_product[i - 1] * nums[i - 1];
        cout<<product<<endl;
        num_pre_product.push_back(product);
    }

    for (int i = nums.size() - 1; i >= 0; --i) {
        int product = i == nums.size() - 1 ? 1 : num_post_product[nums.size() - 1 - i - 1] * nums[i + 1];
        cout<<product<<endl;
        num_post_product.push_back(product);
    }

    for (int i = 0; i < nums.size(); ++i) {
        int product = num_pre_product[i] * num_post_product[nums.size() - 1 - i];
        res.push_back(product);
    }

    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<endl;
    }

    return res;
}

int main(int argc, char *argv[]) {
    vector<int> nums;
    
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    productExceptSelf(nums);
    return 0;
}


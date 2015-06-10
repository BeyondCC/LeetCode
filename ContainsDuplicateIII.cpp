/* 
 * Author: cc
 * Date  : 2015-06-10
 * Source: https://leetcode.com/problems/contains-duplicate-iii/ 
 * Description:
 * Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<math.h>

using namespace std;

struct TreeNode{
    TreeNode *left;
    TreeNode *right;
    int val;
    int index;
    TreeNode(int value, int i) : left(NULL), right(NULL), val(value), index(i) {}
};

TreeNode* insertNode(TreeNode *tree, int value, int index){
    if (tree == NULL) {
        TreeNode *node = new TreeNode(value, index);
        return node;
    }

    if (tree->val > value) {
        tree->left = insertNode(tree->left, value, index);
    }else{
        tree->right = insertNode(tree->right, value, index);
    }

    return tree;
}

bool inorder(TreeNode *tree, int k, int t) {
    stack<TreeNode*> st;
    TreeNode *pre = NULL;

    while(tree != NULL || st.size() > 0)
    {
        while(tree)
        {
            st.push(tree);
            tree = tree->left;
        }

        if (st.size() > 0) {
            if (pre == NULL) {
                pre = st.top();
                st.pop();

                tree = pre->right;
            }else{
                TreeNode *top = st.top();

                if (abs(top->val - pre->val) <= t &&  abs(top->index - pre->index) <= k) {
                    return true;
                }

                tree = top->right;
                pre = top;
                st.pop();
            }

            if (pre) {
                cout<<"pre:"<<pre->val<<endl;
            }

            if (tree) {
                cout<<"current:"<<tree->val<<endl;
            }
        }

    }

    return false;
}
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    unordered_map<int, int> dict;

    if (nums.size() < k || nums.size() == 0) {
        return false;
    }
    TreeNode *root = new TreeNode(nums[0], 0);
    for (int i = 1; i < nums.size(); ++i) { 
        root = insertNode(root, nums[i], i);
    }


    return inorder(root, k, t);
}

int main(int argc, char *argv[]) {
    vector<int> nums;

    nums.push_back(2);
    nums.push_back(2);

    cout<<containsNearbyAlmostDuplicate(nums, 3, 0)<<endl;
    return 0;
}


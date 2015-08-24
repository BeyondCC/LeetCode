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

bool inorder(TreeNode *tree, int k, int t, int size) {
    stack<TreeNode*> st;
    TreeNode *pre = NULL;

    TreeNode **list = new TreeNode*[size];
    int count = 0;

    while(tree != NULL || st.size() > 0)
    {
        while(tree)
        {
            st.push(tree);
            tree = tree->left;
        }

        if (st.size() > 0) {
            TreeNode *top = st.top();

            for (int i = count - 1; i >= 0 ; --i) {
                TreeNode *pre = list[i];
                if (abs(top->val - pre->val) > t ) {
                    break;
                }
                if (abs(top->val - pre->val) <= t &&  abs(top->index - pre->index) <= k) {
                    return true;
                }
            }             

            list[count++] = top;
            tree = top->right;
            st.pop();

            cout<<"visit: "<<top->val<<endl;
            //if (pre) {
            //    cout<<"pre:"<<pre->val<<endl;
            //}

            //if (tree) {
            //    cout<<"current:"<<tree->val<<endl;
            //}
        }

    }

    return false;
}
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    unordered_map<int, int> dict;

    if (nums.size() == 0) {
        return false;
    }
    TreeNode *root = new TreeNode(nums[0], 0);
    for (int i = 1; i < nums.size(); ++i) { 
        root = insertNode(root, nums[i], i);
    }


    return inorder(root, k, t, nums.size());
}

int main(int argc, char *argv[]) {
    vector<int> nums;

    nums.push_back(-1);
    nums.push_back(-1);

    cout<<containsNearbyAlmostDuplicate(nums, 1, -1)<<endl;
    return 0;
}


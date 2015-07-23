/* 
 * Author: cc
 * Date  : 2015-07-23
 * Source: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * Description:
 * Given a binary tree, find the maximum path sum.

 The path may start and end at any node in the tree.

 For example:
 Given the below binary tree,

        1
              / \
                   2   3
                   Return 6.
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

//the return  value is the max of (root, root + left, root+ right);
//while update the maxSum should condider the root + left
//each node should update the maxSum
int helper(TreeNode* root, int &maxSum) {
    if (!root) {
        return 0;
    }

    int leftSum = helper(root->left, maxSum);
    int rightSum = helper(root->right, maxSum);


    int leftArc = leftSum + root->val;
    int rightArc = rightSum + root->val;
    int crossArc = rightSum + root->val + leftSum;

    int localMax = max(leftArc, max(rightArc, root->val));
   
    maxSum = max(maxSum, crossArc);
    maxSum = max(maxSum, localMax);
    return localMax;
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    int sum = helper(root, maxSum);
    cout<<maxSum<<endl;
    return sum > maxSum ? sum : maxSum;
}

int main(int argc, char *argv[]) {
    TreeNode* n1 = new TreeNode(-2);
    TreeNode* n2 = new TreeNode(-1);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;

    cout<<maxPathSum(n1)<<endl;
    return 0;
}


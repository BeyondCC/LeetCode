/* 
 * Author: cc
 * Date  : 2015-07-05
 * Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * Description:
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findPositionOfRoot(TreeNode *root, int flag)
{
    if (!root) {
        return 0;
    }

    return 1 +findPositionOfRoot(root->left, 1) + (flag == 1 ? findPositionOfRoot(root->right, 1) : 0);
}

int helper(TreeNode *root, int k, int flag)
{
    int position = findPositionOfRoot(root, 0);
    cout<<root->val<<" "<<position<<endl;

    if (position == k) {
        return root->val;
    }

    if (position < k) {
        return helper(root->right, k - position, flag);
    }

    if (position > k) {
        return  helper(root->left, k, flag);
    }

    return -1;
}

int kthSmallestPro(TreeNode* root, int k) {

    return helper(root, k, 0);
}

//inorder to visit the Treenode
int kthSmallest(TreeNode* root, int k) {
    TreeNode *visit = root;
    stack<TreeNode*> stk;

    while(visit || !stk.empty())
    {
        while(visit)
        {
            stk.push(visit);
            visit = visit->left;
        }

        if (!stk.empty()) {
            TreeNode *top = stk.top();

            k--;
            if (k == 0) {
                return top->val;
            }

            visit = top->right;
            stk.pop();
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    TreeNode *node = new TreeNode(10);
    TreeNode *node1 = new TreeNode(8);
    TreeNode *node2 = new TreeNode(15);
    TreeNode *node3 = new TreeNode(6);
    TreeNode *node4 = new TreeNode(9);
    TreeNode *node5 = new TreeNode(14);
    TreeNode *node6 = new TreeNode(18);

    node->left = node1;
    node->right = node2;
//    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;

    for (int i = 1; i < 6; ++i) {
        cout<<kthSmallestPro(node, i)<<endl;
    }

    return 0;
}


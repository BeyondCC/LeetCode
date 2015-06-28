/* 
 * Author: cc
 * Date  : 2015-06-28
 * Source: https://leetcode.com/problems/binary-tree-right-side-view/
 * Description:
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 For example:
 Given the following binary tree,
    1            <---
     /   \
     2     3         <---
      \     \
        5     4       <---
        You should return [1, 3, 4].
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

int iter(TreeNode* node, vector<int> &res, int height, int max_height) {
  
    if (node == NULL) {
        //pay attention to the max height
        return height > max_height ? height - 1 : max_height;
    }

    if (height > max_height) {
        res.push_back(node->val);
    }

    int right_height = iter(node->right, res, height + 1, max_height);
    int left_height = iter(node->left, res, height + 1, right_height);

    return left_height;
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;

    if (root == NULL) {
        return res;
    }

    iter(root, res, 1, 0);

    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<endl;
    }

    return res;
}


int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(3);
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(4);
    TreeNode *root3 = new TreeNode(5);
    TreeNode *root4 = new TreeNode(2);
    TreeNode *root5 = new TreeNode(5);
    TreeNode *root6 = new TreeNode(7);

    root->left  = root1;
    root->right = root2;
    root1->right = root4;
    root2->right = root5;
//    root3->left = root6;

    rightSideView(root);

    return 0;
}


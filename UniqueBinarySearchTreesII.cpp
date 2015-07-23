/* 
 * Author: cc
 * Date  : 2015-07-23
 * Source: https://leetcode.com/problems/unique-binary-search-trees-ii/
 * Description:
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

 For example,
 Given n = 3, your program should return all 5 unique BST's shown below.

    1         3     3      2      1
        \       /     /      / \      \
             3     2     1      1   3      2
                 /     /       \                 \
                    2     1         2                 3
                    confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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


vector<TreeNode*> helper(int left, int right) {
    vector<TreeNode*> res;

    if (left > right) {
        res.push_back(NULL);
        return res;
    }

    for (int i = left; i <= right; ++i) {
        vector<TreeNode*> leftList = helper(left, i - 1);
        vector<TreeNode*> rightList = helper(i + 1, right);

        for (int j = 0; j < leftList.size(); ++j) {
            for (int k = 0; k < rightList.size(); ++k) {
                TreeNode *root = new TreeNode(i);
                root->left = leftList[j];
                root->right = rightList[k];

                res.push_back(root);
            }
        }
    }

    return res;
}

/*
 * just visit each num in range n, 
 * all the tree cases is all the left tree cases multiply the right tree cases
 */
vector<TreeNode*> generateTrees(int n) {
    return helper(1, n);
}

int main(int argc, char *argv[]) {
    generateTrees(2);
    return 0;
}


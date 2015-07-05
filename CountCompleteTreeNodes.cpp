/* 
 * Author: cc
 * Date  : 2015-07-05
 * Source: https://leetcode.com/problems/count-complete-tree-nodes/
 * Description:
 * Given a complete binary tree, count the number of nodes.

 Definition of a complete binary tree from Wikipedia:
 In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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

int get_height(TreeNode *root)
{
    int height = 0;

    while(root)
    {
        height++;
        root = root->left;
    }

    return height;
}

int helper(TreeNode *root, int count, int max_height)
{
    if (!root) {
        return count + 1 + pow(2, max_height - 1) - 1;
    }
    int left_height = get_height(root->left) + 1;
    int right_height = get_height(root->right) + 1;

    if (max_height < left_height) {
        max_height = left_height;
    }

    cout<<count<<" "<<max_height<<endl;
    if (root->left && !root->right) {
        //compute the res
        return count + 1 + pow(2, max_height - 1) - 1;
    } 

    if (left_height == right_height) {
        return helper(root->right, count + pow(2, left_height - 2), max_height);
    }else{
        return helper(root->left, count, max_height);
    }
}
//use divide and conquer to visit less nodes
int countNodes(TreeNode* root) {
    return helper(root, 0, 0);
}

int countNodesLow(TreeNode* root) {
    TreeNode *visit = root;
    stack<TreeNode*> stk;
    int res = 0;
    int height = 0;
    int count = 0;
    int max_height = 0;

    while(visit || !stk.empty())
    {
        while(visit)
        {
            stk.push(visit);
            visit = visit->left;
            height++;
        }

        if (height > max_height) {
            max_height = height;
        }

        if (!stk.empty()) {
            TreeNode *top = stk.top();
            if (height == max_height) {
                count++;
            }else{
                if (top->left == NULL && top->right == NULL) {
                    break;
                }
            }
            
            if (top->right) {
                visit = top->right;
            }else{
                height--;
            }

            stk.pop();
        }
    }

    cout<<max_height<<endl;
    cout<<pow(2, max_height - 2) - 1<<endl;
    res = pow(2, max_height - 2) - 1 + count;
    return res;
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
    node1->left = node3;
    node1->right = node4;
//    node2->left = node5;
//    node2->right = node6;

    cout<<countNodes(node)<<endl;

    return 0;
}


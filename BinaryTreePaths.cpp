/* 
 * Author: cc
 * Date  : 2015-08-31
 * Source: https://leetcode.com/problems/binary-tree-paths/
 * Description:
 * Given a binary tree, return all root-to-leaf paths.

 For example, given the following binary tree:

    1
     /   \
     2     3
      \
        5
        All root-to-leaf paths are:

        ["1->2->5", "1->3"]
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

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        TreeNode* visit = root;
        stack<TreeNode*> stk;
        vector<string> res;
        string tmp;
        TreeNode* pre = NULL;

        while(visit != NULL || !stk.empty()) {
            while(visit != NULL) {
                if (tmp.size() == 0) {
                    string s = int2Char(visit->val);
                    tmp.append(s);
                }else{
                    tmp.push_back('-');
                    tmp.push_back('>');
                    string s = int2Char(visit->val);
                    tmp.append(s);
                }
                stk.push(visit);
                visit = visit->left;
            }

            if (!stk.empty()) {
                TreeNode* top = stk.top();
                
                if (top->right != NULL && top->right != pre) {
                    visit = top->right;
                }else{
                    if (top->left == NULL && top->right == NULL) {
                        res.push_back(tmp);
                    }
                    stk.pop();
                    pre = top;
                    cout<<tmp<<endl;
                    if (tmp.size() >= 3) {
                        while((tmp.back() >= '0' && '9' >= tmp.back()) || tmp.back() == '-') {
                            tmp.pop_back();
                        }
                        tmp.pop_back();
                        tmp.pop_back();
                    }
                }
            }
        }

        cout<<"end"<<endl;
        cout<<res.size()<<endl;
        for (int i = 0; i < res.size(); ++i) {
            cout<<res[i]<<endl;
        }

        return res;
    }

    string int2Char(int num) {
        string s = std::to_string(num);

        return s;
    } 
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(-11);
    TreeNode *root1 = new TreeNode(-2);
    TreeNode *root2 = new TreeNode(-3333);
    TreeNode *root3 = new TreeNode(-3335);

    root->left = root1;
    root->right = root2;
    root1->left = root3;

    Solution s;
    s.binaryTreePaths(root);
    return 0;
}


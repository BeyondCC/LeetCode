/* 
 * Author: cc
 * Date  : 2015-08-23
 * Source: http://www.nowcoder.com/books/coding-interviews/b736e784e3e34731af99065031301bca?rp=1
 * Description:
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
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        vector<int> tmp;

        helper(root, expectNumber, tmp, res);

        for (int i = 0; i < res.size(); ++i) {
            vector<int> row = res[i];

            for (int j = 0; j < row.size(); j++) {
                cout<<row[j]<<" "; 
            }
            cout<<endl;
        }
        return res;
    }

    void helper(TreeNode *root, int num, vector<int> &tmp, vector<vector<int> > &res) {
        if (root == NULL) {
            return;
        }

        if (root->left == NULL && root->right == NULL) {
            if (root->val == num) {
                tmp.push_back(root->val);
                res.push_back(tmp);
                tmp.pop_back(); //need to pop the node
            }
            return;
        }

        if (num < 0) {
            return;
        }

        tmp.push_back(root->val);
        if (root->left != NULL) {
            helper(root->left, num - root->val, tmp, res);
        }
        
        if (root->right != NULL) {
            helper(root->right, num - root->val, tmp, res);
        }

        tmp.pop_back();
    }
};

int main(int argc, char *argv[]) {
    TreeNode* node = new TreeNode(10);
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(12);
    TreeNode* node3 = new TreeNode(4);
    TreeNode* node4 = new TreeNode(7);

    node->left = node1;
    node->right = node2;

    node1->left = node3;
    node1->right = node4;

    Solution s;
    s.FindPath(node, 22);

    return 0;
}


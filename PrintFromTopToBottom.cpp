/* 
 * Author: cc
 * Date  : 2015-08-21
 * Source: 
 * Description:
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>

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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
            queue<TreeNode*> q;
            vector<int> res;
             
            if(root == NULL) {
                cout<<"fanzao"<<endl;
                return res;
            }
        
            q.push(root);
            while(!q.empty()) {
                    TreeNode *front = q.front();
                    res.push_back(front->val);
                
                    if(front->left)
                        q.push(front->left);
                
                    if(front->right) 
                        q.push(front->right);
                
                    q.pop();
            }
    
            for (int i = 0; i < res.size(); ++i) {
                cout<<res[i]<<endl; 
            }
            return res;
    }
};

int main(int argc, char *argv[]) {
    TreeNode* root = new TreeNode(1);
    TreeNode* root1 = new TreeNode(2);
    TreeNode* root2 = new TreeNode(3);
    TreeNode* root3 = new TreeNode(4);
    TreeNode* root4 = new TreeNode(5);
    root->left = root1;
    root->right = root2;
    root1->left = root3;
    root1->right = root4;

    Solution s;
    s.PrintFromTopToBottom(root);

    return 0;
}


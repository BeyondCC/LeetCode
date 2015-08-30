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

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    //pre在in中找到根节点的位置，根节点位置的左边构成根节点的左子树，右方构成根节点的右子树
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        if(pre.size() == 0|| in.size() == 0)
            return NULL;
        return getRoot(pre, in, 0, pre.size() -1);
    }
    
    struct TreeNode* getRoot(vector<int> &pre, vector<int> &in, int start, int end) {
        
        if( start > end)
            return NULL;
        
        struct TreeNode *root = new TreeNode(pre[0]);
        cout<<"root val:"<<root->val<<" "<<start<<" "<<end<<endl;
       int index = 0;
        for(int i = start; i <= end; i++) {
                if(root->val == in[i]) {
                    index = i;
                    break;
                }
        }
        
        pre.erase(pre.begin());
        root->left = getRoot(pre, in, start, index -1);
        root->right = getRoot(pre, in, index + 1, end);
        
        return root;
    }
};

int main(int argc, char *argv[]) {
    vector<int> pre;
    vector<int> in;

    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(7);
    pre.push_back(3);
    pre.push_back(5);
    pre.push_back(6);
    pre.push_back(8);

    in.push_back(4);
    in.push_back(7);
    in.push_back(2);
    in.push_back(1);
    in.push_back(5);
    in.push_back(3);
    in.push_back(8);
    in.push_back(6);

    Solution s;
    
    s.reConstructBinaryTree(pre, in);
    return 0;
}


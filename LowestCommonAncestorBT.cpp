/* 
 * Author: cc
 * Date  : 2015-07-14
 * Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * Description:
 Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

 According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

         _______3______
                /              \
                    ___5__          ___1__
                       /      \        /      \
                          6      _2       0       8
                                   /  \
                                            7   4
                                            For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
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
    TreeNode(int x) : val(x), left(0), right(0) {}
};


TreeNode* createTree(int a[], int n)
{
    if (n<=0) return 0;

        TreeNode **tree = new TreeNode*[n];

        for(int i=0; i<n; i++) {
            if (a[i]==0 ){
                tree[i] = 0;
                continue;
            }
            tree[i] = new TreeNode(a[i]);
        }
                    
		int pos=1;
                        
		for(int i=0; i<n && pos<n; i++) {
                
            if (tree[i]){
		    tree[i]->left = tree[pos++];
            
            if (pos<n){
                tree[i]->right = tree[pos++];                                                                            
            }
             
            }
        }
        return tree[0];
}

void findTreeNode(TreeNode* root, TreeNode *p, TreeNode *q, vector<TreeNode*> &tmp, vector<vector<TreeNode*> >&ret) {
    cout<<root->val<<endl;
    tmp.push_back(root);
    if (root == p || root == q) {
        ret.push_back(tmp);
    }

    if (root->left) {
        findTreeNode(root->left, p, q, tmp, ret);
        tmp.pop_back();
    }

    if (root->right) {
        findTreeNode(root->right, p, q, tmp, ret);
        tmp.pop_back();
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> tmp;
    vector<vector<TreeNode*> > ret;
    TreeNode *res = root;
    findTreeNode(root, p, q, tmp, ret);

    int start = ret[0].size() - 1 < ret[1].size() - 1 ? ret[0].size() - 1 : ret[1].size() - 1;

    while(start >= 0)
    {
        if (ret[0][start] == ret[1][start]) {
            res = ret[0][start];
            break;
        }
        start--;
    }
    return res;
}
//get the ancestor nodes of two nodes and then compare them
void printTree_pre_order(TreeNode *root)
{
    if (root == 0){
        //cout << "# ";
        return ;
    }
        
    cout << root->val << " ";
    printTree_pre_order(root->left);
    printTree_pre_order(root->right);
}

int main(int argc, char *argv[]) {
    int a[] = {-1, 1, 3};
    TreeNode *root = createTree(a, sizeof(a)/sizeof(int));

    TreeNode *p = new TreeNode(-1);
    TreeNode *q = new TreeNode(1);

    TreeNode *res = lowestCommonAncestor(root, p, q); 
    cout<<res->val<<endl;
    return 0;
}


/* 
 * Author: cc
 * Date  : 2015-07-12
 * Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Description:
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

 According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

         _______6______
                /              \
                    ___2__          ___8__
                       /      \        /      \
                          0      _4       7       9
                                   /  \
                                            3   5
                                            For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
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


TreeNode* createTree(int a[], int n)
{
    if (n<=0) return NULL;

        TreeNode **tree = new TreeNode*[n];

        for(int i=0; i<n; i++) {
            if (a[i]==0 ){
                tree[i] = NULL;
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

void findTreeNode(vector<TreeNode*> &stk, TreeNode* root, TreeNode *node) {
    stk.push_back(root);
    
    cout<<stk.size()<<endl;
    if (root->val == node->val) {
        return;
    }else if(root->val < node->val) {
         findTreeNode(stk, root->right, node);
    }else{
        findTreeNode(stk, root->left, node);
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) {
       return root;
    }

    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    return root;
}
//get the ancestor nodes of two nodes and then compare them
TreeNode* lowestCommonAncestorPre(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> stack_p;
    vector<TreeNode*> stack_q;

    findTreeNode(stack_p, root, p);
    findTreeNode(stack_q, root, q);

    TreeNode *res = root;

    int index = 0;
    while(index < stack_p.size() && index < stack_q.size())
    {
        TreeNode *top_p = stack_p[index];
        TreeNode *top_q = stack_q[index];

        if (top_p->val == top_q->val) {
            res = top_p;
        }else{
            return res;
        }
        index++;
    }

    return res;
}


void printTree_pre_order(TreeNode *root)
{
    if (root == NULL){
        //cout << "# ";
        return ;
    }
        
    cout << root->val << " ";
    printTree_pre_order(root->left);
    printTree_pre_order(root->right);
}

int main(int argc, char *argv[]) {
    //int a[] = {6, 2, 8, 1, 4, 7, 9};
    int a[] = {2, 0, 3};
    TreeNode *root = createTree(a, sizeof(a)/sizeof(int));
//    printTree_pre_order(root);

    TreeNode *p = new TreeNode(3);
    TreeNode *q = new TreeNode(2);

    TreeNode *res = lowestCommonAncestor(root, p, q); 
    cout<<res->val<<endl;
    return 0;
}


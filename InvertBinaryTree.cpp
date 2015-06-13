/* 
 * Author: cc
 * Date  : 2015-06-13
 * Source: https://leetcode.com/problems/invert-binary-tree/
 * Description:
 * Invert a binary tree.

      4
    /   \
   2     7
  / \   / \
 1   3 6   9
            to
                 4
               /   \
              7     2
            / \   / \
            9   6 3   1
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

vector<int> preorder(TreeNode *root);
vector<int> preorder(TreeNode * root)
{
    vector<int> v;
    vector<TreeNode*> stack;

    if(root)
        stack.push_back(root);

    while(stack.size() > 0)
    {
        TreeNode *node = stack.back();
        v.push_back(node->val);
        stack.pop_back();

        if(node->right)
            stack.push_back(node->right);

        if(node->left)
            stack.push_back(node->left);
    }
    return v;
}


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

void printArray(vector<int> v)
{
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void swap(TreeNode *&left, TreeNode *&right)
{
}

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    TreeNode *tmp = root->right;
    root->right = root->left;
    root->left = tmp;

    root->left = invertTree(root->left);
    root->right = invertTree(root->right);

    return root;
}

int main()
{
    TreeNode *noe = new TreeNode(7);
    int a[] = {1, 2, 3, 4, 5};
    TreeNode* p = createTree(a, sizeof(a)/sizeof(int));

    printTree_pre_order(invertTree(p));    
    return 0;
}

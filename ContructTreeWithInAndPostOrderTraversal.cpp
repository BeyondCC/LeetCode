// Source : https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author : Cheng Chen
// Date   : 2015-02-02

/********************************************************************************** 
  * Given inorder and postorder traversal of a tree, construct the binary tree.
  *
  * Note:
  * You may assume that duplicates do not exist in the tree.
  **********************************************************************************/

#include<iostream>
#include<vector>
#include<stack>

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

TreeNode *helper(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd) {
    
    if (inStart > inEnd)
    {
        return NULL;
    }

    int rootIndex = 0;
    for(int i = inStart; i <= inEnd; i++) {
        if (postorder[postEnd] == inorder[i])
        {
            rootIndex = i;
            break;
        }
    }

    TreeNode *root = new TreeNode(postorder[postEnd]);

    int leftOffset = rootIndex - inStart;
    root->left = helper(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftOffset - 1);
    root->right = helper(inorder, rootIndex + 1, inEnd, postorder, postStart + leftOffset, postEnd - 1);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            
    if (inorder.size() == 0)
    {
        return NULL;
    }
// we can use hashmap to get the index of the root
    return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}

int main()
{
    vector<int> post;
    vector<int> in;

    post.push_back(4);
    post.push_back(5);
    post.push_back(2);
    post.push_back(6);
    post.push_back(7);
    post.push_back(3);
    post.push_back(1);

    in.push_back(4);
    in.push_back(2);
    in.push_back(5);
    in.push_back(1);
    in.push_back(6);
    in.push_back(3);
    in.push_back(7);


    TreeNode *root = buildTree(in, post);

    printTree_pre_order(root);
    return 0;
}

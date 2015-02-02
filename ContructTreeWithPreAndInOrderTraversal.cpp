// Source : :https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : Cheng Chen
// Date   : 2015-02-02

/********************************************************************************** 
  *  Given preorder and inorder traversal of a tree, construct the binary tree.
  *
  *  Note:
  *  You may assume that duplicates do not exist in the tree.
  *               
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

void printArray(vector<int> v)
{
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

TreeNode *helper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd) {
    
    if (preStart > preEnd)
    {
        return NULL;
    }

    int rootIndex = 0;
    for(int i = inStart; i <= inEnd; i++) {
        if (preorder[preStart] == inorder[i])
        {
            rootIndex = i;
            break;
        }
    }

    TreeNode *root = new TreeNode(preorder[preStart]);

    int leftOffset = rootIndex - inStart;
    root->left = helper(preorder, preStart + 1, preStart + leftOffset, inorder, inStart, rootIndex - 1);
    root->right = helper(preorder, preStart + leftOffset + 1, preEnd, inorder, rootIndex + 1, inEnd);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            
    if (preorder.size() == 0)
    {
        return NULL;
    }
// we can use hashmap to get the index of the root
    return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

int main()
{
    vector<int> pre;
    vector<int> in;

    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(5);
    pre.push_back(3);
    pre.push_back(6);
    pre.push_back(7);

    in.push_back(4);
    in.push_back(2);
    in.push_back(5);
    in.push_back(1);
    in.push_back(6);
    in.push_back(3);
    in.push_back(7);


    TreeNode *root = buildTree(pre, in);

    printTree_pre_order(root);
    return 0;
}

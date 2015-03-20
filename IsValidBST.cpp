// Source : https://oj.leetcode.com/problems/validate-binary-search-tree/# 
// Author : Cheng Chen
// Date   : 2015-01-31

/********************************************************************************** 
  *  Given a binary tree, determine if it is a valid binary search tree (BST).
  *
  *  Assume a BST is defined as follows:
  *
  *  The left subtree of a node contains only nodes with keys less than the node's key.
  *  The right subtree of a node contains only nodes with keys greater than the node's key.
  *  Both the left and right subtrees must also be binary search trees.
  *
  *               
  **********************************************************************************/

#include<iostream>
#include<vector>
//#include<stack>

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

bool isValidBSTHelper(TreeNode *root, long minValue, long maxValue) {
    if (root == NULL)
    {
        return true;
    }

    if (root->val > maxValue || root->val < minValue)
    {
        return false;
    }

    return isValidBSTHelper(root->left, minValue, root->val) && isValidBSTHelper(root->right, root->val, maxValue);
}


//有效的二插查找树，中序遍历是升序的
//所以中序遍历这棵树，当前节点跟前驱进行比较
bool helper(TreeNode *root, TreeNode *&pre){

    if (root == NULL)
    {
        return true;
    }
    //遍历左子树
    bool leftFlag = helper(root->left, pre);

    if (pre)
    {
        cout<<"pre:"<<(pre)->val<<endl;
        cout<<"root:"<<root->val<<endl;
    }
    if (pre != NULL && ((pre)->val) >= root->val)
    {
        return false;
    }
//当前节点设置为前驱
    pre = root;

    return leftFlag && helper(root->right, pre);
}

void printArray(vector<int> v)
{
        for(int i=0; i<v.size(); i++){
                    cout << v[i] << " ";
                        }
            cout << endl;
}

bool isValidBST(TreeNode *root){
    TreeNode *tmp =NULL;
    return helper(root, tmp);
//    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

int main()
{
    TreeNode *noe = new TreeNode(7);
    int a[] = {1, 1};
    TreeNode* p = createTree(a, sizeof(a)/sizeof(int));
    printTree_pre_order(p);
    cout <<"is valid binary search tree"<<isValidBST(p);
    return 0;
}

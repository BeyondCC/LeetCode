// Source : https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : Cheng Chen
// Date   : 2015-02-01

/********************************************************************************** 
  * Given a binary tree, flatten it to a linked list in-place.
  *
  * For example,
  * Given
  *
  *          1
  *         / \
  *        2   5
  *       / \   \
  *      3   4   6
  *     The flattened tree should look like:
  *                                       1
  *                                           \
  *                                                2
  *                                                      \
  *                                                             3
  *                                                                     \
  *                                                                              4
  *                                                                                        \
  *                                                                                                   5
  *                                                                                                               \
  *                                                                                                                            6
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

void DFS(TreeNode *root, TreeNode *&right)
{
    if (root)
    {
        //右子树，左子树，根，
        DFS(root->right, right);
        DFS(root->left, right);

        root->right = right;
        right = root;
        root->left = NULL;
    }
}

void flatten(TreeNode *root) {
    if (!root)
    {
        return ;
    }

    TreeNode *right = NULL;
    DFS(root, right);

    printTree_pre_order(root);
}

int main()
{
    TreeNode *noe = new TreeNode(7);
    int a[] = {1, 2, 3, 4, 5};
    TreeNode* p = createTree(a, sizeof(a)/sizeof(int));
    //printTree_pre_order(p);
    cout<<endl;

    flatten(p);
    return 0;
}

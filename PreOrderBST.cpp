// Source : https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
// Author : Cheng Chen
// Date   : 2014-11-02

/********************************************************************************** 
  * 
  * Given a binary tree, return the preorder traversal of its nodes' values.
  * 
  * For example:
  * Given binary tree {1,#,2,3},
  * 
  *    1
  *     \
  *      2
  *     /
  *    3
  * 
  * return [1,2,3].
  * 
  * Note: Recursive solution is trivial, could you do it iteratively?
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
                                                                                    tree[i]->right = tree[pos++];                                                                            }
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

int main()
{
    TreeNode *noe = new TreeNode(5);
    int a[] = {1,2,3,4,5,0,6,0,0,7,8,9,0};
    TreeNode* p = createTree(a, sizeof(a)/sizeof(int));
    printTree_pre_order(p);
    cout << endl;
    vector<int> v = preorder(p);
    printArray(v);
    cout << endl;
    return 0;
}

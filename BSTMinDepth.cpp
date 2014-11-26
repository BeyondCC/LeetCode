// Source : https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/ 
// Author : Cheng Chen
// Date   : 2014-11-02

/********************************************************************************** 
  * Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node. 
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

int min(int a, int b)
{
	return a > b ? b : a;
}

int minDepth(TreeNode *root) 
{
	 if(root == NULL)
                return 0;

        if(root->left == NULL  && root->right == NULL)
                return 1;

        if(root->left == NULL)
            return minDepth(root->right) + 1;

        if(root->right == NULL)
            return minDepth(root->left) + 1;

        return 1 + min(minDepth(root->left), minDepth(root->right));
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
    
    int depth = minDepth(p);
    cout<<"depth:"<<depth<<endl;
    cout << endl;
    return 0;
}

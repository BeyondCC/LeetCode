// Source : https://oj.leetcode.com/problems/path-sum/ 
// Author : Cheng Chen
// Date   : 2014-11-24

/********************************************************************************** 
  * 
  * Given a binary tree and a sum, determine if the tree has a root-to-leaf path  * such that adding up all the values along the path equals the given sum.
  *
  * For example:
  * Given the below binary tree and sum = 22,
  * 
  * 
  * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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

 bool dfs(TreeNode *node, int currentSum, int sum) {

        if(node == NULL)

            return false;

        

        if(node->left == NULL && node->right == NULL)

            return currentSum + node->val == sum;

            

        else

            return dfs(node->left, currentSum + node->val, sum) || dfs(node->right, currentSum + node->val, sum);

 }

    

bool hasPathSum(TreeNode *root, int sum) {
	
	return dfs(root, 0, sum);
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
    int a[] = {5, 4, 8, 11, 0, 13, 4, 7, 0, 0, 2, 0, 0, 0, 1};
    TreeNode* p = createTree(a, sizeof(a)/sizeof(int));
    printTree_pre_order(p);
    cout << endl;
    cout<<"has path sum "<< hasPathSum(p, 22);
    cout << endl;
    return 0;
}

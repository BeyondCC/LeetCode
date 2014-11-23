// Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author : Cheng Chen
// Date   : 2014-11-23

/********************************************************************************** 
  * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root). 
  *   
  **********************************************************************************/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom(TreeNode *root);
vector<vector<int> > levelOrderBottom(TreeNode *root){
  queue<TreeNode*> q;
  vector<int> level;
  vector<vector<int> > result;

  int current = 0; //record the count of the current level
  int next    = 0; //record the cout of the next level
  if(root)
    {
      current = 1;
      q.push(root);
    }

  while(q.size() > 0)
    {
      TreeNode *node = q.front();
      current--;
      level.push_back(node->val);
      q.pop();

      if(node->left)
	{
	  next++;
	  q.push(node->left);
	}

      if(node->right)
	{
	  next++;
	  q.push(node->right);
	}

      if(current == 0)
	{
	  result.push_back(level);
	  level.clear();
	  current = next;
	  next = 0;
	}
    }

  vector<vector<int> > real;
  for(int i = result.size() - 1; i >= 0; i--)
    {
      real.push_back(result[i]);
    }
    
  return real;
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
    vector<vector<int> > v = levelOrderBottom(p);

    for(int i = 0; i < v.size(); i++)
      {
	vector<int> interV = v[i];
	for(int j = 0; j < interV.size(); j++)
	  {
	    cout<<interV[j]<<" ";
	  }

	cout<<endl;
      }

    cout << endl;
    return 0;
}

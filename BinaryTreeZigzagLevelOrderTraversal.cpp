// Source : 
// Author : Cheng Chen
// Date   : 2015-02-12

/********************************************************************************** 
  *  Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
  *
  *  For example:
  *  Given binary tree {3,9,20,#,#,15,7},
  *      3
  *     / \
  *    9  20
  *      /  \
  *     15   7
  *                  return its zigzag level order traversal as:
  *                  [
  *                  [3],
  *                  [20,9],
  *                  [15,7]
  *                  ]
  *               
  **********************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>

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

// level visit the tree, insert NULL node to each level, and then reverse the even level, time O(n)
// also we can use two stack, one stack to visit the current level, the another to store the next level stack
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<TreeNode *> visitQueue;
    vector<vector<int> > res;
    bool reverse = false;
    int index = 0;

    if (root == NULL) {
        return res;
    }

    visitQueue.push_back(root);
    visitQueue.push_back(NULL);

    while(!visitQueue.empty())
    {
        int size = visitQueue.size();
        if (size - 1 <= index) {
            break;
        }
        for (int i = index; i < size; ++i) {
            if (visitQueue[i]) {
                if (visitQueue[i]->left) {
                    visitQueue.push_back(visitQueue[i]->left);
                }

                if (visitQueue[i]->right) {
                    visitQueue.push_back(visitQueue[i]->right);
                }
            }
        }
        
        visitQueue.push_back(NULL);
        index = size;
    }

    for (int i = 0; i < visitQueue.size(); ++i) {
        vector<int> row;

        if (!reverse) {
            while(visitQueue[i]) {
                row.push_back(visitQueue[i]->val);
                i++;
            }
            reverse = true;
        }else{
            while(visitQueue[i]) {
                row.insert(row.begin(), visitQueue[i]->val);
                i++;
            }
            reverse = false;
        }

        if (row.size() > 0) {
            res.push_back(row);
        }
    }


    for (int i = 0; i < res.size(); ++i) {
        vector<int> row = res[i];

        for (int j = 0; j < row.size(); ++j) {
            cout<<row[j]<<" ";
        }
        cout<<endl;
    }
    return res;
}
int main()
{
    TreeNode *noe = new TreeNode(7);
    int a[] = {3, 9, 20, 0, 0, 15, 7};
    TreeNode* p = createTree(a, sizeof(a)/sizeof(int));


    vector<vector<int> > v;
    zigzagLevelOrder(p);
    //printTree_pre_order(p);

    return 0;
}

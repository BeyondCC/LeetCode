// Source : https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/ 
// Author : Cheng Chen
// Date   : 2015-01-31

/********************************************************************************** 
  *  
  *Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

  An example is the root-to-leaf path 1->2->3 which represents the number 123.

  Find the total sum of all root-to-leaf numbers.

  For example,

      1
     / \
    2   3
    
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.

    Return the sum = 12 + 13 = 25.
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

int sumOfStack(stack<TreeNode*> root)
{
    int sum = 0;

    while(!root.empty())
    {
        sum += root.top()->val;
        root.pop();
    }

    cout<<"sum:"<<sum<<endl;
    return sum;
}

int sumNumbers(TreeNode *root) {           
    
    TreeNode *visit = root;
    TreeNode *lastVisit = NULL;

    int sum = 0;
    int pathSum = 0;
    stack<TreeNode*> s;
    
    while(visit || s.size() > 0)
    {
        while(visit)
        {
            s.push(visit);
            pathSum = pathSum * 10 + visit->val;
            visit = visit->left;
        }

        if (!s.empty())
        {
            //the topNode should not be the visit node while it will in death loop in the above while loop
            TreeNode *topNode = s.top();

            if (!topNode->left && !topNode->right)
            {
                sum += pathSum; 
            }

            if (topNode->right && topNode->right != lastVisit)
            {
                visit = topNode->right;
            }else{
                s.pop();
                pathSum /= 10;
                lastVisit = topNode;
            }
        }
    }

    return sum;
}

int main()
{
    TreeNode *noe = new TreeNode(7);
    int a[] = {1, 2, 3, 4, 5};
    TreeNode* p = createTree(a, sizeof(a)/sizeof(int));
    printTree_pre_order(p);
    cout<<endl;

    cout<<"the sum of root to leaf path  is "<<sumNumbers(p)<<endl;
    return 0;
}

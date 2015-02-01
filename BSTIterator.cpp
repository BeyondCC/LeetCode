// Source : https://oj.leetcode.com/problems/binary-search-tree-iterator/
// Author : Cheng Chen
// Date   : 2015-02-01

/********************************************************************************** 
  * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
  *
  * Calling next() will return the next smallest number in the BST.
  *
  * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
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

class BSTIterator{
    public:
        vector<int> vec;
        int size;
        int current;

        BSTIterator(TreeNode *root) {
             inorderTree(root, vec);                    
             current = 0;
             size = vec.size();
        }

        void inorderTree(TreeNode *root, vector<int> &vec)
        {
            TreeNode *visit = root;
            stack<TreeNode *> s;

            while(visit || !s.empty())
            {

                while(visit)
                {
                    s.push(visit);
                    visit = visit->left;
                } 

                if (!s.empty())
                {
                    visit = s.top();
                    vec.push_back(visit->val);

                    visit = visit->right;
                    s.pop();
                }
            }
        }

        bool hasNext() {
            if (current < size)
            {
                return true;
            }
            return false;   
        }

        int next() {
            return vec[current++];
        }
    
        void printArr() {
            int i; 
            for (i = 0; i < size; ++i)
            {
                cout<<vec[i]<<" ";
            }
        }
};

int main()
{
    TreeNode *noe = new TreeNode(7);
    int a[] = {1, 2, 3, 4, 5};
    TreeNode* p = createTree(a, sizeof(a)/sizeof(int));
    printTree_pre_order(p);
    cout<<endl;

    BSTIterator i = BSTIterator(p);
    //i.printArr();

    while(i.hasNext())
    {
        cout<<i.next()<<endl;
    }
    return 0;
}

// Source : https://oj.leetcode.com/problems/recover-binary-search-tree/
// Author : Cheng Chen
// Date   : 2015-02-01

/********************************************************************************** 
  *  Two elements of a binary search tree (BST) are swapped by mistake.
  *
  *  Recover the tree without changing its structure.
  *
  *  Note:
  *  A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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

void swap(TreeNode *&fst, TreeNode *&snd)
{
    int tmp = fst->val;
    fst->val = snd->val;
    snd->val = tmp;
}

//中序遍历，当pre > current时，证明当前节点是交换过得节点, 交换的节点可能是相邻节点，也可能是不相邻，不相邻节点，第一个节点是pre，第二个节点是遍历的visit节点
//time O(n), space O(1)
void recoverTree(TreeNode *root) {
    TreeNode *visit = root;
    stack<TreeNode *> s;
    TreeNode *pre = NULL;
    TreeNode *fst = NULL;
    TreeNode *fstNext = NULL;
    TreeNode *snd = NULL;
    TreeNode *sndNext = NULL;

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
            cout<<"visit:"<<visit->val<<endl;
            if (pre)
            {
                if (pre->val > visit->val)
                {
                    if (fst)
                    {
                        snd = visit;
                    }else{
                        fst = pre;
                        fstNext = visit;
                    }
                }
            }
            
            pre = visit;
            
            visit = visit->right;
            s.pop();
        }
    }

    cout<<"here"<<endl;
    if (fst)
    {
        cout<<"fst"<<endl;
        cout<<fst->val<<endl;
        cout<<fstNext->val<<endl;
    }

    if (snd)
    {
        cout<<"snd"<<endl;
        cout<<snd->val<<endl;
    }

    if (fst && snd)
    {
        swap(fst, snd);
    }else{
        swap(fst, fstNext);
    }
}

int main()
{
    TreeNode *noe = new TreeNode(9);
    int a[] = { 6, 4, 8, 7, 5, 2, 9, 1, 3};
    TreeNode* p = createTree(a, sizeof(a)/sizeof(int));
    printTree_pre_order(p);
    cout<<endl;

   recoverTree(p); 
   cout<<"after swap"<<endl;
   printTree_pre_order(p);
    return 0;
}

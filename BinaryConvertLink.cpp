/* 
 * Author: cc
 * Date  : 2015-08-30
 * Source: http://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?rp=2&ru=/ta/coding-interviews
 * Description:
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:

    //中序遍历而已
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        std::stack<TreeNode*> stk;
        TreeNode*visit = pRootOfTree;
        
        if(visit == NULL)
            return NULL;
        TreeNode*res = NULL;
        bool flag = false;
        TreeNode*pre = NULL;
        
        while(visit != NULL || !stk.empty()) {
                while(visit != NULL) {
                    stk.push(visit);
                    visit = visit->left;
                }    
            
                if(!stk.empty()) {
                    TreeNode *top = stk.top();
                    
                    
                    if(!flag) {
                        res = top;
                        flag = true;
                    }
                    
                    if(pre != NULL) {
                        pre->right = top;
                        top->left = pre;
                    }
                    pre = top;
                    
                    if(top->right != NULL) {
                        visit = top->right;
                    }
                    
                    stk.pop();
                }
        }
        
        return res;
         
    }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(5);
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    TreeNode *root3 = new TreeNode(5);
    TreeNode *root4 = new TreeNode(5);
    

    root->left = root1;
    root->right = root2;

    Solution s; 
    s.Convert(root);
    return 0;
}


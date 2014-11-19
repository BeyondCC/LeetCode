/**

 * Definition for binary tree

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

class Solution {

public:

    bool isSymmetric(TreeNode *root) {

            if(root == NULL)

                return 1;

                

            return isLeftEqualToRight(root->left, root->right);

    }

    

    bool isLeftEqualToRight(TreeNode *left, TreeNode *right) {

        if(!left && !right)

            return 1;

        

        if(left && right)

        {

            if(left->val == right->val)

                return (isLeftEqualToRight(left->left, right->right) && isLeftEqualToRight(left->right, right->left));

        }

        

        return 0;

    }

};

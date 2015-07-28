/* 
 * Author: cc
 * Date  : 2015-07-23
 * Source: https://leetcode.com/problems/path-sum-ii/
 * Description:
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
               5
                            / \
                                        4   8
                                                   /   / \
                                                             11  13  4
                                                                      /  \    / \
                                                                              7    2  5   1
                                                                              return
                                                                              [
                                                                                 [5,4,11,2],
                                                                                    [5,8,4,5]

                                                                              ]
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void getPath(vector<vector<int> > &res, vector<int> tmp, TreeNode* root, int sum, int currSum) {
    if (!root) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->val + currSum == sum) {
            cout<<currSum<<" "<<root->val<<endl;
        
            tmp.push_back(root->val);
            for (int i = 0; i < tmp.size(); ++i) {
                cout<<tmp[i]<<" ";
            }
            cout<<endl;
            res.push_back(tmp);
            return;
        }
    }

    if (root->left) {
        tmp.push_back(root->val);
        getPath(res, tmp, root->left, sum, currSum + root->val); 
        //just remember to remove the last element
        tmp.pop_back();
    }

    if (root->right) {
        tmp.push_back(root->val);
        getPath(res, tmp, root->right, sum, currSum + root->val);
        tmp.pop_back();
    }
}

vector<vector<int> > pathSum(TreeNode* root, int sum) {
    vector<vector<int> >res;
    vector<int> tmp;

    getPath(res, tmp, root, sum, 0);


    cout<<endl;
    for (int i = 0; i < res.size(); ++i) {
        vector<int> row = res[i];

        for (int j = 0; j < row.size(); ++j) {
            cout<<row[j]<<" ";
        }

        cout<<endl;
    }

    return res;
}

int main(int argc, char *argv[]) {
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(8);
    TreeNode* n4 = new TreeNode(11);
    TreeNode* n5 = new TreeNode(13);
    TreeNode* n6 = new TreeNode(4);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(2);
    TreeNode* n9 = new TreeNode(5);
    TreeNode* n10 = new TreeNode(1);


    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    n4->left = n7;
    n4->right = n8;
    n6->left = n9;
    n6->right = n10;

    pathSum(n1, 22); 
    return 0;
}


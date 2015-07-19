/* 
 * Author: cc
 * Date  : 2015-07-18
 * Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * Description:
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
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


void preVisit(TreeNode* head)
{
    if (!head) {
        return;
    }

    cout<<head->val<<endl;

    preVisit(head->left);
    preVisit(head->right);
}

//use fast-slow pointer to cut the list and then use recursive to generate the binary search tree
TreeNode* sortedListToBST(ListNode* head) {
    if (!head) {
        return NULL;
    }

    if (!head->next) {
        return new TreeNode(head->val);
    }

    ListNode* fast = head->next->next;
    ListNode* slow = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    TreeNode* root = new TreeNode(slow->next->val);
    cout<<root->val<<endl;
    root->right = sortedListToBST(slow->next->next);
    slow->next = NULL;
    root->left = sortedListToBST(head);

    return root;
}

void sort(TreeNode* root) {
    cout<<"here"<<endl;
    preVisit(root);
}

int main(int argc, char *argv[]) {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    sort(sortedListToBST(n1));
    
    return 0;
}



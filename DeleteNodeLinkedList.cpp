/* 
 * Author: cc
 * Date  : 2015-07-16
 * Source: https://leetcode.com/problems/delete-node-in-a-linked-list/
 * Description:
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

 Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
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
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deleteNode(ListNode* node) {
    ListNode *next = node->next;
    node->val = next->val;
    node->next = next->next;
}

int main(int argc, char *argv[]) {
    return 0;
}


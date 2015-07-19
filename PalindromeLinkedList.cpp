/* 
 * Author: cc
 * Date  : 2015-07-19
 * Source: https://leetcode.com/problems/palindrome-linked-list/
 * Description:
 * Given a singly linked list, determine if it is a palindrome.

 Follow up:
 Could you do it in O(n) time and O(1) space?
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

bool isPalindromeRecursive(ListNode* head, ListNode* &node) {
    if (head == NULL) {
        return true;
    }
    bool res = isPalindromeRecursive(head->next, node);

    if (!res) {
        return res;
    }
    if (head->val != node->val) {
        return false;
    }

    node = node->next;

    return true;
}

//can use stack, reverse the half list, the character of the recursive to detect
bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    ListNode* fast = head->next->next;
    ListNode* slow = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast == NULL) {
        ListNode* node = slow->next;
        slow->next = NULL;
        return isPalindromeRecursive(head, node);
    }else{
        ListNode* node = slow->next->next;
        slow->next = NULL;
        return isPalindromeRecursive(head, node);
    }
}

int main(int argc, char *argv[]) {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(2);
    ListNode* n5 = new ListNode(1);
    ListNode* n6 = new ListNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    //n5->next = n6;

    cout<<isPalindrome(n1)<<endl;
    return 0;
}


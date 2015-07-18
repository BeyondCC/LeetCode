/* 
 * Author: cc
 * Date  : 2015-07-18
 * Source: https://leetcode.com/problems/rotate-list/
 * Description:
 * Given a list, rotate the list to the right by k places, where k is non-negative.

 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.

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

ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;

    while(head)
    {
        ListNode* cur = head;
        head = head->next;
        cur->next = pre;
        pre = cur;
    }

    return pre;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (!head) {
        return head;
    }
    int length = 0;
    ListNode* visit = head;
    while(visit)
    {
        visit = visit->next;
        length++;
    }

    k = k % length;

    if (!k) {
        return head;
    }
    ListNode *first = head;
    ListNode *second = head;
    ListNode *res = head;

    while(k && second)
    {
        second = second->next;
        k--;
    }

    if (!k && !second) {
        return head;
    }

    while(second->next)
    {
        first = first->next;
        second = second->next;
    }

    res = first->next;
    first->next = NULL;
    second->next = head;

    while(res)
    {
        cout<<res->val<<endl;
        res = res->next;
    }
    return res;
}


int main(int argc, char *argv[]) {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

   n1->next = n2;
    n2->next = n3;
//    n3->next = n4;
    n4->next = n5;

    rotateRight(n1, 2000000000);
    return 0;
}


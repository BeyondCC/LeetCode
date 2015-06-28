/* 
 * Author: cc
 * Date  : 2015-06-28
 * Source:https://leetcode.com/problems/swap-nodes-in-pairs/
 * Description:
 * Given a linked list, swap every two adjacent nodes and return its head.

 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.

 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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

void printList(ListNode *list)
{
    while(list)
    {
        cout<<list->val<<endl;
        list = list->next;
    }
}

ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }        
   
    ListNode *pre = NULL;
    ListNode *visit = head;
    ListNode *next = NULL;
    ListNode *next_next = NULL;

    while(visit && visit->next)
    {
        next = visit->next;
        next_next = next->next;

        if (pre == NULL) {
            head = next;
            next->next = visit;
            visit->next = next_next;
        }else{
            pre->next = next;
            next->next = visit;
            visit->next = next_next;
        }

        pre = visit;
        visit = pre->next;

    }

    return head;
}


int main(int argc, char *argv[]) {
    ListNode *node = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);

    node->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    printList(node);
    node = swapPairs(node);

    printList(node);

    
    return 0;
}


/* 
 * Author: cc
 * Date  : 2015-07-20
 * Source: https://leetcode.com/problems/reverse-nodes-in-k-group/
 * Description:
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

 You may not alter the values in the nodes, only nodes itself may be changed.

 Only constant memory is allowed.

 For example,
 Given this linked list: 1->2->3->4->5

 For k = 2, you should return: 2->1->4->3->5

 For k = 3, you should return: 3->2->1->4->5
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

ListNode* reverse(ListNode *head, ListNode * tail){
    ListNode* pre = NULL;
    ListNode* cur = NULL;

    while(head != tail)
    {
        cur = head;
        head = head->next;

        if (!pre) {
            pre = cur;
            pre->next = NULL;
        }else{
            cur->next = pre;
            pre = cur;
        }
    }

    tail->next = pre;

    return tail;
}

ListNode* reverseKGroup(ListNode* head, int k) {    
    if (k <= 1) {
        return head;
    }
    ListNode* res = NULL;
    ListNode* tail = NULL;
    ListNode* groupTail = NULL;
    ListNode* groupHead = NULL;
    ListNode* preHead = head;
    int length = 1;
    
    while(head)
    {
        groupTail = preHead;
        head = preHead;
        while(length < k && head)
        {
            head = head->next;
            length++;
        }

        if (head) {
            preHead = head->next;
        }

        if (length < k) {
            if (!tail) {
                return preHead;
            }else{
                while(groupTail)
                {
                    tail->next = groupTail;
                    tail = tail->next;
                    groupTail = groupTail->next;
                }
            }
        }else{
            if (head) {
                groupHead = reverse(groupTail, head);
                
                if (!res) {
                    res = groupHead;
                    tail = groupTail;
                }else{
                    tail->next = groupHead;
                    tail = groupTail;
                }
            }else{
                // while head is null, append the remain nodes to the tail
                if (!tail) {
                    return preHead;
                }else{
                    while(groupTail)
                    {
                        tail->next = groupTail;
                        tail = tail->next;
                        groupTail = groupTail->next;
                    }
                }
            }
            length = 1;
        }
    }

    if (tail) {
        tail->next = NULL;
    }

    while(res)
    {
        cout<<res->val<<endl;
        res = res->next;
    }

    return res;
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
    //n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    reverseKGroup(n1, 2);
    return 0;
}


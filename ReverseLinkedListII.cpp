/* 
 * Author: cc
 * Date  : 2015-07-19
 * Source: https://leetcode.com/problems/reverse-linked-list-ii/
 * Description:
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.

 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,

 return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m > n) {
        return head;
    }

    ListNode* visit = head;
    ListNode* preHead = NULL;
    ListNode* tail  = NULL;
    int index = 1;
    int flag  = 0;

    while(visit)
    {
        ListNode* cur = visit;
        visit = visit->next;

        if (index < m) {
            preHead = cur; 
            //be care of the total reverse case
        }else if (index == m) {
            if (!preHead) {
                head = cur;
                flag = 1;
            }
            cur->next = NULL;
            tail = cur; 
        }else if (m < index && n >= index) {
            if (flag) {
                cur->next = head;
                head = cur;
            }else{
                cur->next = preHead->next;
                preHead->next = cur;
            }
        }else{
            tail->next = cur;
            break;
        }

        index++;
    }

    while (head) {
        cout<<head->val<<endl;
        head = head->next;
    }
    return head;
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

    reverseBetween(n1, 2, 3);
    return 0;
}


/* 
 * Author: cc
 * Date  : 2015-07-22
 * Source: https://leetcode.com/problems/linked-list-cycle-ii/
 * Description:
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Follow up:
 * Can you solve it without using extra space?
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

/*
 * 假设链表头到环的入口点的长度为a，相遇点到环的入口点的长度为x(逆时针), 环的长度为l
 * 对于快慢指针所走的路程分别为s, 2s, 那么存在以下关系式
 * 2s = s + n * l
 * s = a + x
 * 可推出
 * a + x = n * l => a = n * l - x => a = (n - 1) * l + l -x 
 * => 从头结点开始一步步走，于此同时另外一个指针在相遇点一步步走，则两个指针必然在环的入口点相遇
 */
ListNode *detectCycle(ListNode *head) {
    ListNode* fast = NULL;
    ListNode* slow = NULL;

    if (!head || !head->next) {
        return NULL;
    }

    slow = head;
    fast = head->next;

    while(fast != slow)
    {
        if (fast == NULL || slow == NULL) {
            return NULL; 
        }

        if (fast->next) {
            fast = fast->next->next;
        }else{
            fast = NULL;
        }
        slow = slow->next;

        cout<<"fast:"<<fast->val<<endl;
        cout<<"slow:"<<slow->val<<endl;
    }

    fast = fast->next;
    while(head != fast)
    {
        head = head->next;
        fast = fast->next;
    }

    return fast;
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
    n6->next = n4;

    cout<<detectCycle(n1)->val<<endl;

    return 0;
}


/* 
 * Author: cc
 * Date  : 2015-07-20
 * Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/ 
 * Description:
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.
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

//just visit the node until meet the distinct node, O(n)
ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode* res = NULL;
    ListNode* tail = NULL;
    ListNode* visit = head;
    ListNode* next = NULL;

    int length = 0;

    while(visit)
    {    
        next = visit->next;

        //meet the next distinct node
        while(next && (next->val == visit->val))
        {
            next = next->next;
            length++;
        }
        if (length == 0) {
            if (!res) {
                res = visit;
                tail = visit;
            }else{
                tail->next = visit;
                tail = tail->next;
            }
        }else{
            // reset
            length = 0;
        }
        visit = next;        
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
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(2);
    ListNode* n5 = new ListNode(3);
    ListNode* n6 = new ListNode(3);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    deleteDuplicates(n1);

    return 0;
}


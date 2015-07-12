/* 
 * Author: cc
 * Date  : 2015-06-28
 * Source: https://leetcode.com/problems/partition-list/
 * Description:
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

 You should preserve the original relative order of the nodes in each of the two partitions.

 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.
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

void visitListNode(ListNode *list)
{
    while(list)
    {
        cout<<list->val<<endl;
        list = list->next;
    }

    cout<<"end"<<endl;
}
ListNode* partition(ListNode* head, int x) {
    //1 4 3 2 5 2 ,3
    ListNode *visit = head;
    ListNode *preTail = NULL;
    ListNode *preHead = NULL;
    ListNode  *postTail = NULL;
    ListNode *postHead = NULL;
    ListNode *cur = NULL; 
   
    // 2, 1 , 2
    while(visit)
    {
        ListNode *cur = new ListNode(visit->val);
        if (cur->val < x) {
            if (!preHead) {
                preHead = cur;
                preTail = cur;
                if (postHead) {
                    preTail->next = postHead;
                }
            }else{
                cur->next = postHead;
                preTail->next = cur;
                preTail = cur; 
            }
        }else{
            if (!preHead) {
                if (!postHead) {
                    postHead = cur;
                    postTail = cur;
                }else{
                    postTail->next = cur;
                    postTail = cur;
                }
            }else{
                if (!postHead) {
                    postHead = cur;
                    postTail = cur;
                    preTail->next = postHead;
                }else{
                    postTail->next = cur;
                    postTail = cur;
                }
            }
        }

        visitListNode(preHead);
        visit = visit->next;
    }

    if (!preTail) {
        return postHead;
    }else{
        return preHead;
    }

}

int main(int argc, char *argv[]) {
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(1);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(2);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(2);

    n1->next = n2;
    n2->next = NULL;
    //n3->next = n4;
    //n4->next = n5;
    //n5->next = n6;

   ListNode *res = partition(n1, 2);

   while(res)
   {
       cout<<res->val<<endl;
       res = res->next;
   }

    return 0;
}


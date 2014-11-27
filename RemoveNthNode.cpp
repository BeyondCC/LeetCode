// Source : https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/ 
// Author : Cheng Chen
// Date   : 2014-11-28

/********************************************************************************** 
  * Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5. 
  *               
  **********************************************************************************/

#include<iostream>
#include<vector>
//#include<stack>

using namespace std;

 ListNode *removeNthFromEnd(ListNode *head, int n) {

        ListNode *current = head;
        int count = 0;

        while(current)
        {
            count++;
            current = current->next;
        }

        int finalPosition = count - n + 1;

        if(finalPosition == 1)
            return head->next;

        ListNode *pre = NULL;
        current = head;
        count = 0;

        while(current)
        {

            count++;

            if(count == finalPosition)

            {

                pre->next = current->next;

                break;

            }else{

                pre = current;

                current = current->next;

            }

        }

        return head;
    }

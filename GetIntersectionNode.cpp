// Source : https://oj.leetcode.com/problems/intersection-of-two-linked-lists/
// Author : Cheng Chen
// Date   : 2014-11-29

/********************************************************************************** 
  *  
  * Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.              
  **********************************************************************************/

#include<iostream>
#include<vector>

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

class Solution {

public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenOfA = 0, lenOfB = 0;

        

        ListNode *visit = headA;

        ListNode *result = NULL;

        while(visit)

        {

            lenOfA++;

            visit = visit->next;

        }

        

        visit = headB;

        while(visit)

        {

            lenOfB++;

            visit = visit->next;

        }

        

        if(lenOfA == 0 && lenOfB == 0)

            return result;

            

        int startPosition = lenOfA - lenOfB;

        if(startPosition > 0){

            visit = headA;

            while(startPosition > 0) {

                visit = visit->next;

                startPosition--;

            }

            result = headB;

            while(visit != NULL && result != NULL)

            {

                if(visit->val == result->val)

                    return result;

                    

                visit = visit->next;

                result = result->next;

            }

            

        }else{

            visit = headB;

            startPosition = -startPosition;

                  while(startPosition > 0){

                visit = visit->next;

                startPosition--;

            }

            

            result = headA;

            while(visit != NULL && result != NULL)

            {

                if(visit->val == result->val)

                    return result;

                    

                visit = visit->next;

                result = result->next;

            }

        }

        

        return result;

    }

};

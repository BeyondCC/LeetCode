/* 
 * Author: cc
 * Date  : 2015-04-05
 * Source: https://leetcode.com/problems/add-two-numbers/ 
 * Description:
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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

/**
 * just traverse the l1 and l2, attention the jinwei
 * time: O(m + n)
 *
 */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == NULL)
    {
       return l2;
    }

    if (l2 ==  NULL)
    {
        return l1; 
    }

    ListNode *result = NULL;
    ListNode *visit = NULL;
    int jinwei = 0;
    int sum = 0;
    int value = 0;

    while (l1 != NULL && l2 != NULL)
    {
       sum = (l1->val + l2->val + jinwei);
        value = sum % 10;
       jinwei = sum / 10;

       ListNode *newNode = new ListNode(value);

       if (result == NULL)
       {
           result = new ListNode(value);
           visit = result;
       }else{
           visit->next = newNode;
           visit = visit->next;
       }

       l1 = l1->next;
       l2 = l2->next;
    }

    while(l1)
    {
        sum = l1->val + jinwei;
        value = sum % 10;
        jinwei = sum / 10;

        ListNode *newNode = new ListNode(value);
        visit->next = newNode;
        visit = visit->next; 

        l1 = l1->next;
    }

    while(l2)
    {
        sum = l2->val + jinwei;
        value = sum % 10;
        jinwei = sum / 10;

        ListNode *newNode = new ListNode(value);
        visit->next = newNode;
        visit = visit->next; 

        l2 = l2->next;
    }

    if (jinwei)
    {
        ListNode *newNode = new ListNode(jinwei);
        visit->next = newNode;
        visit = visit->next;
    }

    return result;
}

void PrintList(ListNode *l)
{
    while(l)
    {
        cout<<l->val<<endl;
        l = l->next;
    }    
}
int main(int argc, char *argv[]) {
    ListNode *l1 = new ListNode(2);
    ListNode *l2= new ListNode(4);
    ListNode *l3= new ListNode(3);

    l1->next = l2;
    l2->next = l3;


    ListNode *m1 = new ListNode(5);
    ListNode *m2= new ListNode(6);
    ListNode *m3= new ListNode(4);
    ListNode *m4 = new ListNode(4);

    m1->next = m2;
    m2->next = m3;
    m3->next = m4;

    PrintList(addTwoNumbers(l1, m1)); 
    return 0;
}

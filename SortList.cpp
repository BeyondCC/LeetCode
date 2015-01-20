// Source : https://oj.leetcode.com/problems/sort-list/
// Author : Cheng Chen
// Date   : 2014-07-06

/********************************************************************************** 
* 
* Sort a linked list in O(n log n) time using constant space complexity.
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* h);

ListNode *merge(ListNode *left, ListNode *right) {
    if (left == NULL)
    {
        return right;   
    }

    if (right == NULL)
    {
        return left;   
    }

    ListNode *res = new ListNode(0);
    ListNode *head = res;
    ListNode *tmp;

    while(left && right) {
        if (left->val < right->val)
        {
            tmp = new ListNode(left->val);
            left = left->next;
        }else{
            tmp = new ListNode(right->val);
            right = right->next;
        }

        res->next = tmp;
        res = tmp;
    }

    if(left) {
        res->next = left;
    }

    if(right) {
        res->next = right;
    }

    return head->next;
}

//归并排序，找到链表中点，左链表和右链表排序之后，两者进行合并
ListNode *mergeSort(ListNode *head) {
  
    if (head == NULL || head->next == NULL)
    {
        return head;   
    }

    ListNode *walker = head;
    ListNode *runner = head;

    while(walker->next != NULL && runner->next != NULL) {
        ListNode *tmp = runner->next;
        if (tmp->next != NULL)
        {
            walker = walker->next;
            runner = runner->next->next;
        }else{
            break;
        } 
    }

    ListNode *right = walker->next;
    walker->next = NULL;
    ListNode *left = head;
    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

ListNode *sortList(ListNode *head) {
    return mergeSort(head);
}

void printList(ListNode* h)
{
    while(h!=NULL){
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\n");
}

ListNode* createList(int a[], int n)
{
    ListNode *head=NULL, *p=NULL;
    for(int i=0; i<n; i++){
        if (head == NULL){
            head = p = new ListNode(a[i]);
        }else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}


int main(int argc, char** argv)
{
    int n = 10;
    if (argc>1){
        n = atoi(argv[1]);
    }
    srand(time(NULL));

    int *a = new int[n];
    for(int i=0; i<n; i++){
        a[i] = random()%n + 1;
    }

    int b[] = {2, 1, 3};
    ListNode *p = createList(a, n);
    printList(p);
    printList(sortList(p));
    
    delete[] a;
    return 0;
}

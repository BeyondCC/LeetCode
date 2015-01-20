// Source : https://oj.leetcode.com/problems/insertion-sort-list/ 
// Author : Cheng Chen
// Date   : 2014-07-06

/********************************************************************************** 
* 
* Sort a linked list using insertion sort. 
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

ListNode *insertionSortList(ListNode *head) {
    if (head == NULL)
    {
        return head;   
    }

    ListNode *res = NULL;

    while(head)
    {
        ListNode *next = head->next;

        if (res == NULL)
        {
            //tmp acts as the res head node
            res = new ListNode(head->val);
        }else{
            ListNode *visit = res;
            ListNode *preVisit = NULL;
            //search the right position to inseart
            while(visit)
            {
                if (visit->val < head->val)
                {
                    preVisit = visit;
                    visit = visit->next;   
                }else{
                    break;
                }
            }

            if (preVisit)
            {
                preVisit->next = head;
                head->next = visit;
            }else{
                head->next = visit;
                res = head;
            }

        }

        head = next;
    }

    return res;
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
    printList(insertionSortList(p));
    
    delete[] a;
    return 0;
}

// Source : https://oj.leetcode.com/problems/sort-list://leetcode.com/problems/reverse-linked-list/ 
// Author : Cheng Chen
// Date   : 2015-05-13

/********************************************************************************** 
* 
* Reverse a singly linked list.
*               
**********************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* h);


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


ListNode* reverseList(ListNode* head) {
//just allocate a chunk of memory to the res, the res node should be init
    ListNode *res =(ListNode*)malloc(sizeof(ListNode));
    res->val = 0;
    res->next = NULL;
    ListNode *pre = NULL;
    ListNode *tmp = NULL;
    
    while(head)
    {
        tmp = head;
        head = head->next;

        tmp->next = res->next;
        res->next = tmp;
    }

    if (pre) {
        pre->next = NULL;
    }
    return res->next;
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
    printList(reverseList(p));
    
    delete[] a;
    return 0;
}

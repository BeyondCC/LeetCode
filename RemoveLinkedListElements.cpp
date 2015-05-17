// Source : https://leetcode.com/problems/remove-linked-list-elements/
// Author : Cheng Chen
// Date   : 2015-05-13

/********************************************************************************** 
* 
* Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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

ListNode* removeElements(ListNode* head, int val) {
    if (!head) {
        return head;
    }        

    ListNode *res = NULL;
    ListNode *pre = NULL;

    while(head)
    {
        if (head->val != val) {        
            if (pre) {
                pre->next = head;
                pre = pre->next;
            }else{
                res = pre = head;
            }
        }
        head = head->next;
    }

    return res;
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
    printList(removeElements(p, 4));
    
    delete[] a;
    return 0;
}

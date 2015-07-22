/* 
 * Author: cc
 * Date  : 2015-07-20
 * Source: https://leetcode.com/problems/merge-k-sorted-lists/
 * Description:
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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


ListNode* merge(ListNode* first, ListNode* second) {
    ListNode *head = NULL;
    ListNode *tail = NULL;

    while(first && second)
    {
        if (first->val < second->val) {
            if (!head) {
                head = first;
                tail = first;
            }else{
                tail->next = first;
                tail = tail->next;
            }

            first = first->next;
        }else{
            if (!head) {
                head = second;
                tail = second;
            }else{
                tail->next = second;
                tail = tail->next;
            }

            second = second->next;
        }
    }

    if (first) {
        if (tail) {
            tail->next = first;
        }else{
            head = first;
        }
    }

    if (second) {
        if (tail) {
            tail->next = second;
        }else{
            head = second;
        }
    }

    return head;
}

ListNode* mergeList(vector<ListNode*> lists, int low, int high)
{
    ListNode *res = NULL;
    if (low == high) {
        return lists[low];
    }

    if (low + 1 == high) {
        return merge(lists[low], lists[high]);
    }

    int middle = (low + high) / 2;

    ListNode* left = mergeList(lists, low, middle);
    ListNode* right = mergeList(lists, middle + 1, high);

    return merge(left, right);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if(n==0) return NULL;

    while(n>1){
        if(n % 2 == 1) {
            lists[n]=NULL;
            n++;
        }               // to make n even 
        for(int i=0 ; i < (n) / 2 ; i++ ){
            lists[i] = merge( lists[i] , lists[i+ (n / 2)]);
        }

        n = n / 2;
    }

    return lists[0];

}

int main(int argc, char *argv[]) {
    vector<ListNode*> lists;

    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(-1);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

//    n1->next = n2;
    //n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode* n6 = new ListNode(1);
    ListNode* n7 = new ListNode(2);
    ListNode* n8 = new ListNode(3);
    ListNode* n9 = new ListNode(4);

    n6->next = n7;
    n7->next = n8;
    n8->next = n9;

    lists.push_back(n1);
    lists.push_back(NULL);
    lists.push_back(n2);

    ListNode * res = mergeKLists(lists);

    while(res)
    {
        cout<<res->val<<endl;
        res = res->next;
    }
    return 0;
}


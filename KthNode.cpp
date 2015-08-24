/* 
 * Author: cc
 * Date  : 2015-08-21
 * Source: http://www.nowcoder.com/books/coding-interviews/529d3ae5a407492994ad2a246518148a?rp=1
 * Description:
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
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
            ListNode* slow  = pListHead;
            ListNode* fast = pListHead;
        
            while(k && fast != NULL)
            {
                fast = fast->next;
                k--;
            }

        
            if(k > 0)
            {
                return NULL;    
            }
            while(fast != NULL)
             {
                slow = slow->next;
                fast = fast->next;
            }
            
            cout<<slow->val<<endl;
            return slow;        
    }
};

int main(int argc, char *argv[]) {
    ListNode* node = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);

    node->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution s;
    s.FindKthToTail(node, 1);
    return 0;
}


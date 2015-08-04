/* 
 * Author: cc
 * Date  : 2015-08-03
 * Source: https://leetcode.com/problems/implement-queue-using-stacks/ 
 * Description:
 * Implement the following operations of a queue using stacks.

 push(x) -- Push element x to the back of queue.
 pop() -- Removes the element from in front of queue.
 peek() -- Get the front element.
 empty() -- Return whether the queue is empty.
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

class Queue {
    public:
        stack<int> first;
        stack<int> second;

            // Push element x to the back of queue.
        void push(int x) {
            first.push(x);
        }

            // Removes the element from in front of queue.
        void pop(void) {

            while(!first.empty()) {
                int top = first.top();
                
                second.push(top);
                first.pop();
            }

            second.pop();

            while(!second.empty()) {
                int top = second.top();

                first.push(top);
                second.pop();
            }
        }

            // Get the front element.
        int peek(void) {
            while(!first.empty()) {
                int top = first.top();
                
                second.push(top);
                first.pop();
            }

            int res = second.top();

            while(!second.empty()) {
                int top = second.top();

                first.push(top);
                second.pop();
            }
                    
            return res; 
        }

            // Return whether the queue is empty.
        bool empty(void) {
            return first.empty();
        }

};

int main(int argc, char *argv[]) {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout<<q.peek()<<endl;

    q.pop();
    cout<<q.peek()<<endl;

    cout<<q.empty()<<endl;
    return 0;
}


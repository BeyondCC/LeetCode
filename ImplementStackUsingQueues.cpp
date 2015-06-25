/* 
 * Author: cc
 * Date  : 2015-06-26
 * Source: https://leetcode.com/problems/implement-stack-using-queues/
 * Description:
 * Implement the following operations of a stack using queues.

 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 empty() -- Return whether the stack is empty.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Stack {
    vector<int> v;
    public:
            // Push element x onto stack.
        void push(int x) {
            v.push_back(x);
        }

            // Removes the element on top of the stack.
        void pop() {
            v.pop_back();
        }

            // Get the top element.
        int top() {
            return v.back(); 
        }

            // Return whether the stack is empty.
        bool empty() {
            return v.empty();        
        }

};

int main(int argc, char *argv[]) {
    Stack  s;

    for (int i = 0; i < 10; ++i) {
        s.push(i);
    }

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top();
    cout<<s.empty()<<endl;
    return 0;
}


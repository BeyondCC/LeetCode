/*
 * Source: https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
 * Description: Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 For example,
 Given height = [2,1,5,6,2,3],
 return 10.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>

using namespace std;


//time O(n), space time is O(n)
int largestRectangleArea(vector<int> &height) {
    if(height.size() == 0)
        return 0;

    stack<int> sta;
    int global = 0;
    for(int i = 0; i < height.size(); i++) {
        while(!sta.empty() && height[i] <= height[sta.top()]) {
            int index = sta.top();
            sta.pop();
            //while stack is empty the sta[index] is the min range from 0 ~ i -1 
            int area = sta.empty() ? i * height[index] : (i - sta.top() - 1) * height[index];
            global = max(area, global);
        }

        sta.push(i);
    }

    //the stack may be not empty
    while(!sta.empty()) {
        int index = sta.top();
        sta.pop();
        int area = sta.empty() ? height.size() * height[index] : (height.size() - sta.top() - 1) * height[index];
        global = max(area, global);
    }

    return global;

}
int main(int argc, char *argv[]) {
    vector<int> v;
    v.push_back(0);
    v.push_back(9);

    cout<<"the result is"<<largestRectangleArea(v)<<endl;
    return 0;
}


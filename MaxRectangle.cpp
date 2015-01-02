/* Source:https://oj.leetcode.com/problems/maximal-rectangle/
 * Descriptions: Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 *
 *
 */

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

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

//largestRectangleArea is O(n), will call this method 0(n),time O(m * n), space O(n)
int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.size() == 0)
        return 0;
    int size = matrix[0].size();
    vector<int> dp;

    for(int i = 0; i < size; i++) {
        dp.push_back(0);  
    }

    int maxArea = 0;
    for (int i = 0; i < matrix.size(); ++i)
    {   
        vector<char> row = matrix[i];
        for (int j = 0; j < row.size(); ++j)
        {
            dp[j] = row[j] == '1' ? dp[j] + 1 : 0;
        }

        maxArea = max(maxArea, largestRectangleArea(dp));
    }

    return maxArea;
}

int main(int argc, char *argv[]) {
    vector<vector<char> > matrix;

//    for(int i = 0; i < 5; i++) {
        vector<char> row;
        row.push_back('0');
        row.push_back('0');

        matrix.push_back(row);
 //   }

    cout<<"result is "<<maximalRectangle(matrix);

    return 0;
} 

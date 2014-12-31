/*
 * Source: https://oj.leetcode.com/problems/unique-paths/
 * Description:A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

 The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

 How many possible unique paths are there?
<<<<<<< HEAD
=======
 * use dp to calculate the result
 * 1. 可以使用动态规划，也可以使用组合来作,从m + n - 2步中选n - 1或者m - 1，也可以使用暴力破解
 * reference:http://blog.csdn.net/linhuanmars/article/details/22126357
>>>>>>> dea1980fa1fb48bbe040dc7678be2ce35af14c40
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>

using namespace std;

//到达每一个位置可以从上一格和左边一格，只用保存一行遍历的结果存储对应位置上一行的结果
int uniquePathDP(int m, int n) {
    if(m == 0 || n == 0)
        return 0;

    int* result = new int[n];
    for (int i = 0; i < n; i++)
    {
        result[i] = 0;
    }

    result[0] = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 1; j < n; j++ )
            result[j] += result[j - 1];
    }

    return result[n - 1];
}

int uniquePaths(int m, int n) {

    vector<vector<int> > p;
    for(int i = 0; i < m; i++){
        vector<int> tmp;
        for(int j = 0; j< n; j++)
            tmp.push_back(0);
        p.push_back(tmp);
    }


    if(m == 1 || n == 1)
          return 1;
    p[0][0] = 0;
    
    for(int j = 1; j < n; j++) {
        p[0][j] = 1;
    }
            
    for(int j = 1; j < m; j++) {
        p[j][0] = 1;
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++) {
            if(i == 0) {
                p[i][j] = p[i][j - 1];
            }else if(j == 0) {
                p[i][j] = p[i - 1][j];
            }else{
                p[i][j] = p[i - 1][j] + p[i][j - 1];
            }
        }
    }

    return p[m - 1][n -1];
}

int main(int argc, char *argv[]) {
    cout<<uniquePaths(2,2)<<endl;
    return 0;
}


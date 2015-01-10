/*
 * Source: https://oj.leetcode.com/problems/sqrtx/
 * Description:
 * Implement int sqrt(int x).

Compute and return the square root of x.

 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

//牛
int sqrt(int x) {
    if (x == 0) {
        return 0;
    }

    double lastY = 0;
    double y = 1;

    while(y != lastY) {
        lastY = y;
        y = (y + x / y) / 2;
    }

    return (int)y;
}

int main(int argc, char *argv[]) {
    cout<<sqrt(4)<<endl;
    return 0;
}


/* 
 * Author: cc
 * Date  : 2015-05-18
 * Source: https://leetcode.com/problems/happy-number/
 * Description:
 * Write an algorithm to determine if a number is "happy".

 A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

int squareSum(int n);
bool isHappy(int n) {
    int pre = -1;
    int sum = 0;
    vector<int> v;

    while(true) {
        sum = squareSum(n);

        if (sum == 1) {
            return true;
        }
       
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == sum) {
                return false;
            }
        }
        n = sum;
        pre = sum;
        v.push_back(sum);
    }

    return false;
}

int squareSum(int n) {
    int sum = 0;
    int remain = 0;

    while(n) {
        remain = n % 10;
        n = n / 10;

        sum += remain * remain;
    }

    return sum;
}

int main(int argc, char *argv[]) {
    cout<<isHappy(191212121)<<endl;
    return 0;
}


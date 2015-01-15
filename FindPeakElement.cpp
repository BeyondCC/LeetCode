/*
 * Source: https://oj.leetcode.com/problems/find-peak-element/
 * Description:
 * A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

int findPeakElement(const vector<int> &num) {
    int start = 0, end = num.size() - 1;
    int middle = (start + end) / 2;

    while(start <= end) {
           
        if (start == end) {
            return start;
        }

        if (num[middle] > num[middle + 1]) {
            end = middle;
        }else{
            start = middle + 1;
        }

        middle = (start + end) / 2;
    }

    return start;
}

int main(int argc, char *argv[]) {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);

    cout<<"peak index is "<<findPeakElement(v)<<endl;
    return 0;
}


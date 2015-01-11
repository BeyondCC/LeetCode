/*
 * Source: https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * Description:
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

//2种情况，最小元素在左边的数组和在右边的数组两种情况对数组进行切分
//终止情形：最后只会剩下两个元素，要么顺序，要么逆序，直接取出最小即可
//time o(lgn)
int findMin(vector<int> &num) {
    int start = 0;
    int end = num.size() - 1;
    int middle;

    while(start <= end) {
        middle = (start + end) / 2;

        if (num[start] < num[middle] && num[end] < num[start]) {
            start = middle;
        }else if (num[start] > num[middle] && num[middle] < num[end]) {
            end = middle;
        }else if(num[start] <= num[middle] && num[middle] < num[end]){
            return num[start];
        }else{
            return num[end];
        }
    }

    return num[start];
}

int main(int argc, char *argv[]) {
    vector<int> v;

    v.push_back(3);
    v.push_back(2);

    cout<<"min is:"<<findMin(v);
    return 0;
}


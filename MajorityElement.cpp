/*
 * Source: https://oj.leetcode.com/problems/majority-element/
 * Description: Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.


 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>

using namespace std;

int majorityElement(vector<int> &num) {
    int result = num[0];
    int count = 1;

    for(int i = 1; i < num.size(); i++) {
        cout<<"count is "<<count<<endl;

        if(count == 0) {
            result = num[i];
            count++;
            continue;
        }
        if(num[i] == result) {
            count++;
        }else{
            count--;
        }
    }
    
    return result;
}

int main(int argc, char *argv[]) {
    vector<int> num;
    num.push_back(10);
    num.push_back(9);
    num.push_back(9);
    num.push_back(9);
    num.push_back(10);

    cout<<"result is "<<majorityElement(num)<<endl;
    return 0;
}


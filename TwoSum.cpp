/*
 * Source: https://oj.leetcode.com/problems/two-sum/
 * Description:
 *  
 * Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

//time O(n), space O(n)
vector<int> twoSumHash(vector<int> &numbers, int target) {
    vector<int> res;
    unordered_map<int, int> map;

    for (int i = 0; i < numbers.size(); i++) {
        if (map.count(target - numbers[i])) {
            res.push_back(map[target - numbers[i]] + 1);
            res.push_back(i + 1);
        }else{
            map.insert(pair<int, int>(numbers[i], i));
        }
    }
    
    cout<<"0: "<<res[0]<<" "<<res[1]<<endl;
    return res;
}

//time is o(nlgn) + o(n)
vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> res;
    int start = 0;
    int end = numbers.size() - 1;

    sort(numbers.begin(), numbers.end());

    while(start <= end) {
        if (numbers[start] + numbers[end] == target) {
            res.push_back(start);
            res.push_back(end);
            break;
        }else if(numbers[start] + numbers[end] < target){
            start++;
        }else{
            end--;
        }
    }

    return res;
}
int main(int argc, char *argv[]) {
    vector<int> numbers;

    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(11);
    numbers.push_back(5);

    twoSumHash(numbers, 9); 
    return 0;
}


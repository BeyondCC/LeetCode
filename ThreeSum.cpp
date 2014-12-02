/*
 * Source: https://oj.leetcode.com/problems/3sum/
 * Description: Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 *
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArr(vector<int> v);
vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > result;
    vector<int> visit;

    if(num.size() < 3)
        return result;

    sort(num.begin(), num.end());
//-4 -1 -1 0 1 2
    for(int i = 0; i < num.size(); i++) {
        if(num[i] > 0)
            break;
        if(i > 0 && (num[i] == num[i - 1]))
            continue;
        
        int start = i + 1, end = num.size() - 1;
        while(start < end)
        {
            if(start > i + 1 && num[start] == num[start - 1])
                start++;
            else if(end < num.size() - 1 && num[end] == num[end + 1])
                end--;
            else if(num[i] + num[start] + num[end] == 0)
            {
                visit.push_back(num[i]);
                visit.push_back(num[start]);
                visit.push_back(num[end]);
//                printArr(visit);
                result.push_back(visit);
                visit.clear();

                start++;
                end--;
            }else if(num[i] + num[start] + num[end] < 0){
                start++;
           }else
                end--;
        }
    }
    return result;
}

void printArr(vector<int> v) {
    for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<"  ";
    cout<<endl;
}

void printVector(vector<vector<int> > v) {
    for(int i = 0; i < v.size(); i++){
        vector<int> tmp = v[i];

        for(int j = 0; j < tmp.size(); j++) {
            cout<<tmp[j]<<"  ";
        }

        cout<<endl;
    }
}

int main(int argc, char *argv[]) {
    vector<int> v;

    v.push_back(-1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(-1);
    v.push_back(-4);


    vector<vector<int> > result = threeSum(v);
    printVector(result);
    return 0;
}

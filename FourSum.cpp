/*
 * Source: https://oj.leetcode.com/problems/4sum/ 
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArr(vector<int> v);
vector<vector<int> > threeSum(vector<int> &num, int target) {
    vector<vector<int> > result;
    vector<int> visit;

    if(num.size() < 4)
        return result;

    sort(num.begin(), num.end());
//-4 -1 -1 0 1 2
    for(int i = 0; i < num.size() - 3; i++) {
       
        //duplicate
        if(i == 0 || num[i] > num[i - 1]) {
            for(int j = i + 1; j < num.size() - 2; j++){
                if(j == i + 1 || num[j] > num[j - 1]){
                    int start = j + 1, end = num.size() - 1;
                    while(start < end)
                    {
                    if(num[i] + num[j] + num[start] + num[end] == target)
                    {
                        visit.push_back(num[i]);
                        visit.push_back(num[j]);
                        visit.push_back(num[start]);
                        visit.push_back(num[end]);
//                      printArr(visit);
                        result.push_back(visit);
                        visit.clear();

                        start++;
                        end--;
                    
                        //duplicate
                        while(start < end && num[start] == num[start - 1])
                            start++;

                        while(start < end && num[end] == num[end + 1])
                            end--;
                    }else if(num[i] + num[j] + num[start] + num[end] < target){
                        start++;
                    }else
                        end--;
                    }
            }
        }
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
    v.push_back(0);
    v.push_back(-2);
    v.push_back(2);


    vector<vector<int> > result = threeSum(v, 0);
    printVector(result);
    return 0;
}

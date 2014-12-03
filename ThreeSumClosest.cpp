/*
 * Source: https://oj.leetcode.com/problems/3sum-closest/
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArr(vector<int> v);

int abs(int num) {
    return num > 0 ? num : -num;
}

int threeSum(vector<int> &num, int target) {
    int result = 0;
    vector<int> visit;

    if(num.size() < 3)
        return result;

    sort(num.begin(), num.end());
    result = abs(num[0] + num[1] + num[2] - target);
    cout<<"re: "<<result<<endl;
//-4 -1 1 2
    for(int i = 0; i < num.size() - 2; i++) {
       
        //duplicate
        if(i == 0 || num[i] > num[i - 1]) {
            int start = i + 1, end = num.size() - 1;
            while(start < end)
            {
                int sum = num[i] + num[start] + num[end];
                cout<<"sum: "<<sum<<endl;
                if(abs(sum - target) < abs(result)){
                    result = sum;
                    cout<<"result: in: "<<result<<endl; 
                    visit.push_back(num[i]);
                    visit.push_back(num[start]);
                    visit.push_back(num[end]);

                    start++;
                    end--;
                    
                    //duplicate
                    while(start < end && num[start] == num[start - 1])
                        start++;

                    while(start < end && num[end] == num[end + 1])
                        end--;
                }else if(sum < 0){
                    start++;
                }else
                    end--;
            }
        }
    }

    printArr(visit);
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
    v.push_back(2);
    v.push_back(1);
    v.push_back(-4);
    

    int result = threeSum(v, 1);
    cout<<"result: "<<result<<endl;
    return 0;
}

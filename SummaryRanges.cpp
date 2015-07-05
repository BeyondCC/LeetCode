/* 
 * Author: cc
 * Date  : 2015-0705
 * Source: https://leetcode.com/problems/summary-ranges/
 * Description:
 * Given a sorted integer array without duplicates, return the summary of its ranges.

 For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<sstream>

using namespace std;

string itos(int i)
{
    stringstream s;
    s << i;
    return s.str();
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;

    if (nums.size() == 0) {
        return res;
    }
    
    int start = nums[0];
    int end   = nums[0];

    for (int i = 1; i < nums.size(); ++i) { 
        if (nums[i] > end + 1) {
            string s;
            if (start != end) {
                s.append(itos(start));
                s.append("->");
                s.append(itos(end));
            }else{
                s.append(itos(start));
            }

            res.push_back(s);
            start = nums[i];
        }

        end = nums[i];
    }


    string s;
    if (start != end) {
        s.append(itos(start));
        s.append("->");
        s.append(itos(end));
    }else{
        s.append(itos(start));
    }

    res.push_back(s);

    for (int i = 0; i < res.size(); ++i) {
       cout<<res[i]<<endl; 
    }
    return res;
}


int main(int argc, char *argv[]) {
    vector<int> nums;

    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(7);

    summaryRanges(nums);
    return 0;
}


/* 
 * Author: cc
 * Date  : 2015-02-25
 * Source: https://oj.leetcode.com/problems/anagrams/
 * Description:
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 *
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<string> anagrams(vector<string> &strs) {
    int length = strs.size();
    vector<string> result;
    unordered_map<string, vector<string> > filterMap;

    for (int i = 0; i < length; ++i)
    {
        string s = strs[i]; 

        sort(s.begin(), s.end());

        unordered_map<string, vector<string> >::const_iterator findKey = filterMap.find(s);

        if (findKey == filterMap.end())
        {
            vector<string> v;
            v.push_back(strs[i]);
            filterMap.insert(make_pair(s, v));
        }else{
            //update the new value
            vector<string> v = findKey->second;
            v.push_back(strs[i]);
            filterMap[s] = v;
        }
    }

   for (unordered_map<string, vector<string> >::iterator iter = filterMap.begin(); iter != filterMap.end(); iter++)
   {
        vector<string> v = iter->second;

        if (v.size() > 1)
        {
            for (int i = 0; i < v.size(); ++i)
            {
                result.push_back(v[i]);
            }
        }
   }

    return result;
}

int main(int argc, char *argv[]) {
    string s("abcd");
    string s1("dcba");
    string s2("abccccc");
    string s3("cccccab");

    vector<string> v;

    v.push_back(s);
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    
    vector<string> res = anagrams(v);

    for (int i = 0; i < res.size(); ++i)
    {
        cout<<res[i]<<endl;
    }
    
    return 0;
}


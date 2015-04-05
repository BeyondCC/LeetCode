/* 
 * Author: cc
 * Date  : 2015-04-05
 * Source: https://leetcode.com/problems/compare-version-numbers/
 * Description:
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<int> splitWithDotChar(string s) {
    string tmp = "";
    vector<int> res;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '.')
        {
            res.push_back(stoi(tmp));
            tmp = "";
        }else{
            tmp += s[i];
        }
    }

    res.push_back(stoi(tmp));
    return res;
}

int compareVersion(string version1, string version2) {
    vector<int> spitVector1 = splitWithDotChar(version1);
    vector<int> spitVector2 = splitWithDotChar(version2);

    int minSize = min(spitVector1.size(), spitVector2.size());

    for (int i = 0; i < minSize; ++i)
    {
        if (spitVector1[i] > spitVector2[i])
        {
            return 1;
        }

        if (spitVector1[i] < spitVector2[i])
        {
            return -1; 
        }
    }

    // attention the 1.0 with 1
    for (int i = minSize; i < spitVector1.size(); ++i)
    {
       if (spitVector1[i] != 0)
       {
           return 1;
       } 
    }

    for (int i = minSize; i < spitVector2.size(); ++i)
    {
        if (spitVector2[i] != 0)
        {
            return -1;
        }
    }

    return 0;
} 

int main(int argc, char *argv[]) {
    cout<<compareVersion("1.0", "1")<<endl;
    return 0;
}


/* 
 * Author: cc
 * Date  : 2015-08-03
 * Source: https://leetcode.com/problems/valid-anagram/ 
 * Description:
 * Given two strings s and t, write a function to determine if t is an anagram of s.

 For example,
 s = "anagram", t = "nagaram", return true.
 s = "rat", t = "car", return false.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        bool isAnagram(string s, string t) {
            unordered_map<char, int> dict;
            int count = 0;

            for (int i = 0; i < s.size(); ++i) {
                if (dict.find(s[i]) == dict.end()) {
                    dict.insert(make_pair(s[i], 1));
                }else{
                    count = dict[s[i]];
                    count++;
                    dict[s[i]] = count;
                }
            }

            for (int i = 0; i < t.size(); ++i) {
                if (dict.find(t[i]) == dict.end()) {
                    return false;
                }else{
                    count = dict[t[i]];
                    if (count == 0) {
                        return false;
                    }
                    --count;
                    dict[t[i]] = count;
                }
            }

            //determine whether each key in dicts is mateched
            for (unordered_map<char, int>::iterator iter = dict.begin(); iter != dict.end(); iter++) {
                if (iter->second != 0) {
                    return false;
                }
            }
            return true;
        }
};

int main(int argc, char *argv[]) {
    Solution s;

    cout<<s.isAnagram("ab", "a")<<endl;
    return 0;
}


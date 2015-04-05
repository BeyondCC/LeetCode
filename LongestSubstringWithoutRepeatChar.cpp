/* 
 * Author: cc
 * Date  : 2015-04-
 * Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Description:
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

/**
 * walker and runner to maintain a window, when the runner is in the set, then move the walker to the fittest position
 *
 * time O(n)
 */
int lengthOfLongestSubstring(string s) {

    if (s == "")
    {
        return 0;
    }

    unordered_set<char> set;    

    int walker = 0;
    int runner = 0; 
    int maxLen = 0;

    while(runner < s.length())
    {
        if (set.find(s[runner]) == set.end())
        {
           set.insert(s[runner]);
        }else{
            if (maxLen < runner - walker)
            {
                maxLen = runner - walker;
            }

            while(s[walker] != s[runner])
            {
                set.erase(s[walker]);
                walker++;
            }
            walker++;
        }

        runner++;
    }
    
    maxLen = max(maxLen, runner - walker);
    
    return maxLen;
}   

int main(int argc, char *argv[]) {
    string s = "bbbbbbbb";
    string s1 = "abcabc123456";

    cout<<"result is "<<lengthOfLongestSubstring(s)<<endl;
    cout<<"result is "<<lengthOfLongestSubstring(s1)<<endl;
    return 0;
}


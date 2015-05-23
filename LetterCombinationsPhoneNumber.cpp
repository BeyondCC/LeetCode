/* 
 * Author: cc
 * Date  : 2015-05-23
 * Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Description:
 * Given a digit string, return all possible letter combinations that the number could represent.

 A mapping of digit to letters (just like on the telephone buttons) is given below.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;
vector<string> combination(vector<string> &r, string s, vector<string> &nums, int index);

vector<string> letterCombinations(string digits) {
    vector<string> res;
    vector<string> nums;
    
    if (digits == "") {
        return res;
    }
    unordered_map<char, string> dict;

    dict.insert(make_pair('2', "abc"));
    dict.insert(make_pair('3', "def"));
    dict.insert(make_pair('4', "ghi"));
    dict.insert(make_pair('5', "jkl"));
    dict.insert(make_pair('6', "mno"));
    dict.insert(make_pair('7', "pqrs"));
    dict.insert(make_pair('8', "tuv"));
    dict.insert(make_pair('9', "wxyz"));


    for (int i = 0; i < digits.size(); ++i) {
        nums.push_back(dict[digits[i]]); 
    }

    string s = "";
    res = combination(res, s, nums, 0);

    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<endl;
    }

    return res;
}

//recursive to get the combination
vector<string> combination(vector<string> &r, string s, vector<string> &nums, int index)
{
    string str = nums[index];

    if (index == nums.size() - 1) {
        for (int i = 0; i < str.size(); ++i) {
            string tmp = s;
            tmp.push_back(str[i]); 
            r.push_back(tmp);
        } 

        return r;
    }

    for (int i = 0; i < str.size(); ++i) {
        string tmp = s;
        tmp.push_back(str[i]);
        r = combination(r, tmp, nums, index + 1);        
    }
    
    return r;
}
int main(int argc, char *argv[]) {
    letterCombinations("23284238424298489234");
    return 0;
}


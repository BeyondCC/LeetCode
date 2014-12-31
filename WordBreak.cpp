/*
 * Source:https://oj.leetcode.com/problems/word-break/
 * Description: Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

 For example, given
 s = "leetcode",
 dict = ["leet", "code"].

 Return true because "leetcode" can be segmented as "leet code".

 use DP

 动态规划的核心在于，确定历史信息以及存储的数据结构，每次操作是否需要抵用历史信息，并确定递推表达式
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<unordered_set>
 
using namespace std;

void printBoolArr(bool *arr, int n) {

	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

bool wordBreak(string s, unordered_set<string> &dict) {	

	bool *res = new bool[s.length() + 1];
    for(int i = 0; i < s.length() + 1; i++)
        res[i] = false;
	res[0] = true; // init state

	for (int i = 0; i < s.length(); ++i)
	{
		string tmp = s.substr(0, i + 1);
		for (int j = 0;j <= i; j++)
		{
			if(res[j] && dict.count(tmp))
			{
				res[i + 1] = true;
                break;
			}
			tmp.erase(0, 1);
		}
	}
	return res[s.length()];
}

int main(int argc, char *argv[]) {
	string s = "aaaaaaa";
	unordered_set<string> dict;
	dict.insert("aaaa");
	dict.insert("aa");

	cout<<wordBreak(s, dict);
    return 0;
}


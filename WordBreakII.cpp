/*
 * Source: https://oj.leetcode.com/problems/word-break-ii/
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 * use DP

 动态规划的核心在于，确定历史信息以及存储的数据结构，每次操作是否需要抵用历史信息，并确定递推表达式
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<unordered_set>
 
using namespace std;

void helper(int start, string s, string item, vector<string> result, unordered_set<string> dict);

void printBoolArr(bool *arr, int n) {

	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

vector<string> wordBreakBrute(string s, unordered_set<string> &dict) {

    vector<string> res;
    helper(0, s, "", res, dict);
    return res;
}

void helper(int start, string s, string item, vector<string> result, unordered_set<string> dict) {

    if(start > s.length()) {
        cout<<"item: "<<item<<endl;
        result.push_back(item);
        return;
    }

    for(int j = start; j < s.length(); j++) {
        string tmp = s.substr(start, j + 1);

        if(dict.count(tmp)){
            if(item.length() == 0 )
                item += tmp;
            else{
                item += " ";
                item += tmp;

            }
            helper(start + j + 1, s, item, result, dict);
        }
        if(j == s.length() - 1)
            cout<<"result:"<<result<<endl;
    }
}


vector<string> wordBreak(string s, unordered_set<string> &dict) {

	bool *res = new bool[s.length() + 1];
    for(int i = 0; i < s.length() + 1; i++)
        res[i] = false;
	res[0] = true; // init state
   
    vector<string> resVector;
    string result;

    for(int i = 0; i < s.length(); i++) {
        if(res[i]){
            for(int j = i; j < s.length(); j++) {
                string tmp = s.substr(i, j + 1);
                cout<<"tmp: "<<tmp<<endl;
                if(dict.count(tmp)){
                    result += tmp;
                    cout<<"add tmp: "<<tmp<<endl;
                    cout<<"j is "<<j + 1<<endl;
                    res[i + j + 1] = true;
                    if(j != s.length() - 1) {
                        result += " ";
                    }
                    break;
                }
            }
        }
    }

    resVector.push_back(result);
	return resVector;
}

void print(vector<string> v)
{
    for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";

    cout<<endl;
}

int main(int argc, char *argv[]) {
	string s = "catsanddog";
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");

	vector<string> res = wordBreakBrute(s, dict);
    print(res);
    return 0;
}


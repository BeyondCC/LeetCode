/*
 * Source: Write a function to find the longest common prefix string amongst an array of strings.
 *
 * time: 2014-11-29
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;
string longestCommonPrefix(vector<string> &strs) {
         string prefixStr;
    int index = 0;

    if(strs.size() != 0) {
    string firstStr = strs[0];

    for(int index = 0; index < firstStr.length(); index++) {
        int i = 1;
        for(; i < strs.size(); i++) {
            string indexStr = strs[i];

            if(indexStr.length() - 1 < index)
                break;

            if(indexStr[index] != firstStr[index])
                break;
        }

        if(i < strs.size())
            break;
        else
            prefixStr += firstStr[index];
    }
	}

    return prefixStr;

}

int main(){
	vector<string> s;
	s.push_back("a");
	s.push_back("abdsf");
	s.push_back("abd");

	cout<<longestCommonPrefix(s);
	return 0;
}

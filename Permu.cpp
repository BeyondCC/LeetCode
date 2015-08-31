/* 
 * Author: cc
 * Date  : 2015-08-21
 * Source: 
 * Description:
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<bool> used(str.size(), false); 
        vector<string> res;
        string tmp;
        
        if(str.size() == 0)
            return res;
        
        sort(str.begin(), str.end());
        helper(str, tmp, used, res);
    
        cout<<res.size()<<endl;
        for (int i = 0; i < res.size(); ++i) {
            cout<<res[i]<<endl; 
        }
        return res;
    }
    
    void helper(string str,  string &tmp, vector<bool> & used, vector<string> &res) {
        if(tmp.size() == str.size()) {
                res.push_back(tmp);
                return;
        }

        for(int i = 0; i < str.size(); i++) {
            if(i > 0 && str[i] == str[i - 1] && !used[i - 1])
                continue;
            if(!used[i]) {
                used[i] = true;        
                tmp.push_back(str[i]);
                helper(str, tmp, used, res);
                tmp.pop_back();
                used[i] = false;
            }
        }
        
        
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    s.Permutation("abc");
    return 0;
}


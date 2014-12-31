#include<iostream>
#include<string>
#include<vector>

using namespace std;

//dp[i][j],k
bool isScramble(string s1, string s2) {

    if(s1.size() != s2.size())
        return 0;

    bool*** res = new bool**[s1.size()];

    for(int i = 0; i < s1.size(); i++){
        res[i] = new bool*[s2.size()];
        for(int j = 0; j < s2.size(); j++) {
            res[i][j] = new bool[s1.size() + 1];
            for(int k = 0; k < s1.size() + 1; k++) {
                if(k == 1)
                    res[i][j][k] = s1[i] == s2[j];
                else
                    res[i][j][k] = 0;
            }
        }
    }
    for(int len = 2; len <= s1.size(); len++) {
        for(int i = 0; i < s1.size() - len + 1; i++) {
            for(int j = 0; j < s2.size() - len + 1; j++) {
                for(int k = 1; k < len; k++) {
                    res[i][j][len]  |= res[i][j][k] && res[i + k][j + k][len - k] || res[i][len + j - k][k] && res[i + k][j][len - k];
                }
            }
        }
    }
    return res[0][0][s1.size()];
}

int main() {
    string s1 = "rgtae";
    string s2 = "great";
    cout<<"result is " <<isScramble(s1, s2);
    return 0;
}

/* 
 * Author: cc
 * Date  : 2015-09-07
 * Source: https://leetcode.com/problems/multiply-strings/
 * Description:
 * Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
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
        string multiply2(string num1, string num2) { 
            int n1 = num1.size();
            int n2 = num2.size();
            vector<int> tmp(n1 + n2, 0);
            int k = n1 + n2 - 2;

            //存储结果的每一位，对每一位进行进位处理
            for (int i = 0; i < n1; ++i) {
                for (int j = 0; j < n2; ++j) {
                    tmp[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
                } 
            }

            int carry = 0;
            for (int i = 0; i < n1 + n2; ++i) {
                tmp[i] += carry;
                carry = tmp[i] / 10;
                tmp[i] = tmp[i] % 10;
            }

            int i = k + 1;
            while(tmp[i] == 0) 
                i--; //除去前面的0

            if (i < 0) {
                return "0";
            }

            string res;

            while(i >= 0) {
                res.push_back(tmp[i] + '0');
                i--;
            }

            return res;
        }

        string multiply(string num1, string num2) {
            int mutiSize = num1.size();
            int mutierSize = num2.size();
            string res;
            vector<string> middleRes;

            int jin = 0;

            if (num1 == "0" || num2 == "0") {
                return "0";
            }

            for (int i = mutiSize - 1; i >= 0; --i) {
                string middle;
                int tmp = 0;
                jin = 0;
                for (int j = mutierSize - 1;  j >= 0; j--) {
                    int n1 = num1[i] - '0';
                    int n2 = num2[j] - '0';

                    tmp = (n1 * n2 + jin) % 10;
                    jin = (n1 * n2 + jin) / 10;
                    //cout<<tmp<<" "<<jin<<endl;
                    middle.insert(0, 1, '0' + tmp);
                }

                if (jin != 0 ) {
                    middle.insert(0, 1, '0' + jin);
                }
               
                for (int k = i + 1; k < mutiSize; k++) {
                    middle.push_back('0'); 
                }
                middleRes.push_back(middle);
            }

            int maxLength = middleRes[middleRes.size() - 1].size();

            for (int i = 0; i < middleRes.size() - 1; ++i) {
                int size = middleRes[i].size();
                cout<<maxLength <<" "<<size<<endl;
                int deta = maxLength - size;

                while(deta > 0) {
                    middleRes[i].insert(0, 1, '0');
                    deta--;
                }
            }

            jin = 0;

            for (int i = 0; i < maxLength; ++i) {
                int tmp = 0;
                for (int j = 0; j < middleRes.size(); j++) {
                    tmp += middleRes[j][maxLength - 1 - i] - '0';
                }

                tmp += jin;
                res.insert(0, 1,  '0' + tmp % 10);
                jin = tmp / 10;
            }

            if (jin > 0) {
                res.insert(0, 1, '0' + jin);
            }

            for (int i = 0; i < middleRes.size(); ++i) {
                cout<<middleRes[i]<<endl;
            }

            return res;
        }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout<<s.multiply2("356", "356")<<endl;
    return 0;
}


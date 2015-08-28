/* 
 * Author: cc
 * Date  : 2015-08-28
 * Source: http://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?rp=2&ru=/ta/coding-interviews
 * Description:
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
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
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
            int res = 0;
         
            if(data.size() < 2){
                *num1 = 0;
                *num2 = 0;
                return;
            }
         
            for(int i = 0; i < data.size(); i++) {
                res ^= data[i];
            }
         
            int bit = getFirstBit(res);
            vector<int> fst;
            vector<int> snd;
         
            for(int i = 0; i < data.size(); i++) {
                if((data[i] & bit )  != 0 ){
                    fst.push_back(data[i]);
                }else{
                    snd.push_back(data[i]);
                }
            }
         
            *num1 = 0;
            *num2 = 0;
            for(int i = 0; i < fst.size(); i++){
                *num1 ^= fst[i];
            }
         
            for(int i = 0; i < snd.size(); i++) {
                *num2 ^= snd[i];
            }
    }
     
    int getFirstBit(int num){
        int res = 0;
        while(num) {
            res = num;
            num = num & (num - 1);
        }
         
        return res;
         
    }
};


int main(int argc, char *argv[]) {
    return 0;
}


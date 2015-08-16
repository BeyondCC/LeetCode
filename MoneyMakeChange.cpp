/* 
 * Author: cc
 * Date  : 2015-08-16
 * Source: 
 * Description:
 * 给定25,10,5,1美分，问计算n分有多少种表示方法
 * resolution:
 * 对于n用25标识的所有方法，n - 0 * 25, n - 1 * 25......
 * 递归计算使用10,5,1的个数
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

int makeChange(int money, int change) {
    int next = 0; 
    int res = 0;

    switch(change) {
        case 25:
           next = 10;
           break;
        case 10:
           next = 5;
           break;
        case 5:
            next = 1;
            break; 
        case 1:
            return 1;
   }

    for (int i = 0; i * change <= money; ++i) {
        res += makeChange(money - i * change, next);    
    }

    return res;
}

int main(int argc, char *argv[]) {
    cout<<makeChange(10, 25)<<endl;
    return 0;
}


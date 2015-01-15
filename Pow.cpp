/*
 * Source: https://oj.leetcode.com/problems/powx-n/
 * Description:
 * Implement pow(x, n).
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

double pow(double x, int n) {
    double res = 1;

    if (n == 1) {
        return x;
    }
    
    if (n == 0) { 
        return 1;
    }

    if (n < 0) {
        n = -n;

        if (n % 2 == 0) {
            return 1.0 / pow(x * x , n / 2);
        }else{
            return 1.0 / (x * pow(x, n - 1));    
        }
    }else{
        if (n % 2 == 0) {
            return  pow(x * x , n / 2);
        }else{
            return  x * pow(x, n - 1);    
        }
    }
}

int main(int argc, char *argv[]) {
    cout<<"res is:" <<pow(34.005, -3);
    return 0;
}


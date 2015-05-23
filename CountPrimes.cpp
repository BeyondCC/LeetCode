/* 
 * Author: cc
 * Date  : 2015-04-23
 * Source: https://leetcode.com/problems/count-primes/
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool isPrime(int n);

int countPrimes(int n) {
    int count = 0;
    int *flag = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i) {
        flag[i] = 0;        
    }

    //from i to i * i <=n, mark the i * 2,3,4 ..... to false
    for (int i = 2; i * i <= n - 1; ++i) {
        if (!flag[i]) {
            for (int j = i; i * j  <= n - 1; ++j) {
                flag[i * j] = 1;
            } 
        }
    }

    for (int i = 2; i <= n -1 ; ++i) {
        if (!flag[i]) {
            count++;
        }
    }
    return count;
} 

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; ++i) {
       if (n % i == 0) {
           return false;
       } 
    }

    return true;
}

int main(int argc, char *argv[]) {
    cout<<countPrimes(499979)<<endl;
    return 0;
}


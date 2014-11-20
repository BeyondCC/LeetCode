#include<iostream>

using namespace std;
/*
 * 回文數
 *
 */

class Solution {

public:

    bool isPalindrome(int x) {

        int revert = 0;

        int remainder = 0;

        

        if(x < 0)

            return 0;

            

        int tmp = x;

        

        while(tmp)

        {

            remainder = tmp % 10;

            tmp = tmp / 10;

            

            revert = revert * 10 + remainder;

        }

        

        

        return x == revert;

    }

};

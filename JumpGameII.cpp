/* 
 * Author: cc
 * Date  : 2015-02-04
 * Source: https://oj.leetcode.com/problems/jump-game-ii/
 * Description:
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//time O(n) space o(n)
int jump(int A[], int n) {
    
    int maxReachPos = 0;
    int numOfJump = 0;

    int *steps = new int[n]();


    for (int i = 0; i < n && i <= maxReachPos; ++i)
    {
        if (A[i] + i > maxReachPos)
        {
            maxReachPos = A[i] + i;
           
            int lastIndex = maxReachPos > n - 1 ? n - 1: maxReachPos;
            for (int j = lastIndex; j > i && steps[j] == 0;j--)
            {
                steps[j] = steps[i] + 1;
            }
        }
    }

    return steps[n - 1];
}

//当i超过了setp-1步能到达的最远距离时，更新step
int jumpPre(int A[], int n) {
   int step = 0;
   int maxReachPos = 0;
   int lastMaxReachPos = 0;

   for (int i = 0; i < n && i <= maxReachPos; ++i)
   {
       if (i > lastMaxReachPos) // step - 1 能都打的最大位置
       {
            step++;
            lastMaxReachPos = maxReachPos;
       }
       maxReachPos = max(maxReachPos, A[i] + i);
   }

   if (maxReachPos < n - 1)
   {
       return 0;
   }

   return step;
}

int main(int argc, char *argv[]) {
    int A[] = {1, 2, 3, 4};

    cout<<"min steps is "<<jumpPre(A, 4);

    return 0;
}


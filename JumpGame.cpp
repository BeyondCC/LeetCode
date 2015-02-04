/*
 * Source: https://oj.leetcode.com/problems/jump-game/
 * Description:
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
 *
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

bool canJump(int A[], int n) {

    bool *flag = new bool[n]();

    flag[0] = true;

    //每一个位置最大可以到达的地方，所经之路置true
    for (int i = 0; i < n; ++i)
    {
        if (!flag[i])
        {
            return false;
        }else{
            //该位置可以直接到达最后一个位置
            if (i + A[i] >= n-1)
            {
                return true;
            }
            
            //防止TLE，从后往前赋值
            for (int j = i + A[i]; j > i && !flag[j]; j--)
            {
                flag[j] = true;
            }
        }
    }

    return flag[n - 1];
}

//time O(n), space O(1)
bool canJumpPre(int A[], int n) {
    
    int maxReachPos = 0;

    //全局最大值和局部最大值
    for (int i = 0; i <= maxReachPos && i < n; ++i)
    {
        maxReachPos = max(i + A[i], maxReachPos);
    }

    return maxReachPos >= n - 1;
}
int main(int argc, char *argv[]) {
    int A[] = {2,3,1,1,4};
    int B[] = {3,2,1,0,4};

    cout<<canJumpPre(A, 5)<<endl;
    cout<<canJumpPre(B, 5)<<endl;

    return 0;
}


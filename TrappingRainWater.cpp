/* 
 * Author: cc
 * Date  : 2015-02-10
 * Source: https://oj.leetcode.com/problems/trapping-rain-water/
 * Description:
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

//从左至右扫描一遍得到每个bar左边的最大高度 leftHeight
//从右至左扫描得到每个bar右边的最大高度 rightHeight
//min(leftHeight, rightHeight) - A[i] > 0 得到每个bar被夹住的最小高度? 加入res ：+0
int trap(int A[], int n) {
    
    int *container = new int[n]();
    int leftMax = 0;
    int res     = 0;

    // get the max height of left of each bar
    for (int i = 0; i < n; ++i)
    {
        container[i] = leftMax;
        leftMax = max(leftMax, A[i]);
    }

    int rightMax = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        //get the min height of left max height and right max height
        container[i] = min(rightMax, container[i]);
        //update the rightMax
        rightMax = max(rightMax, A[i]);

        // update res
        res +=  (container[i] - A[i]) > 0 ? (container[i] - A[i]) : 0;
    }

    return res;
}


//两边夹逼
//当小的一侧向中间靠拢时，如果下一个比当前的高度要小时停止，表示该位置可以注水，如果下一个比当前大时，重新判断两侧高度的大小
//O(n)
int trapPre(int A[], int n) {
    int res = 0;
    int left = 0;
    int right = n - 1;

    while(left < right) {
        
        int minSide = min(A[left], A[right]);

        if (minSide == A[left])
        {
            left++;

            while(left < right)
            {
                if (A[left] < minSide) 
                {
                    res += minSide - A[left];   
                    left++;
                }else{
                    break;
                }
            }
        }else{
            right--;

            while(left < right)
            {
                if (A[right] < minSide)
                {
                    res += minSide - A[right];
                    right--;
                }else{
                    break;
                }
            }
        }       
    }

    return res;
}
int main(int argc, char *argv[]) {

    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout<<trapPre(A, 12)<<endl;
    return 0;
}


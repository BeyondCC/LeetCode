/* 
 * Author: cc
 * Date  : 2015-02-08
 * Source: https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * Description:
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int maxProfitPre(vector<int> &prices) {
    if (prices.size() == 0)
    {
        return 0;
    }

    int result = 0;
//实质是所有相邻两天之差 > 0 的累加
    for (int i = 0; i < prices.size() - 1; ++i)
    {
        int diff = prices[i + 1] - prices[i];

        if (diff)
        {
            result += diff;
        }
    }

    return diff;
}
int maxProfit(vector<int> &prices) {
    
    if (prices.size() == 0)
    {
        return 0;
    }

    int localProfit = prices[0];
    int result = 0;

    for (int i = 1; i < prices.size(); ++i)
    {
        if (localProfit >= prices[i])
        {
            localProfit = prices[i];
        }else{
            result = result + prices[i] - localProfit;
            localProfit = prices[i];
        }
    }

    return localProfit;
}

int main(int argc, char *argv[]) {
    return 0;
}


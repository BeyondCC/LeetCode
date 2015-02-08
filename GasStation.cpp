/* 
 * Author: cc
 * Date  : 2015-02-04
 * Source: https://oj.leetcode.com/problems/gas-station/
 * Description:
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 * Note:
 * The solution is guaranteed to be unique.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;
//
//到当前节点的所剩汽油 < 0,那么从出发节点到当前节点都不会是最终的结果,因为若节点j出发包含之前的油也走不完的花，是不可能是最终的结果
//当所走一圈所剩的汽油 < 0，那么找不到一个节点能完整地走一圈
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    
    int sum = 0;
    int total = 0;
    int position = 0;

    for (int i = 0; i < gas.size(); ++i)
    {
        int diff = gas[i] - cost[i];

        sum += diff;
        total += diff;

        if (sum < 0)
        {
            sum = 0;
            //下一个节点是潜在的结果
            position = i + 1;
        }
    }

    return total >= 0 ? position : -1;
}

int main(int argc, char *argv[]) {

    vector<int> gas;
    vector<int> cost;

    gas.push_back(5);

    cost.push_back(4);

    cout<<canCompleteCircuit(gas, cost)<<endl;

    return 0;
}


#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int maxProfit(vector<int> &prices) {

    if(prices.size() == 0)
        return 0;

    int local = 0;
    int global = 0;

    for(int i = 1; i < prices.size(); i++) {
        local = max(local + prices[i + 1] - prices[i], 0);
        global = max(global, local);
    }

    return global;
}

 int maxProfit1(vector<int> &prices) {
       
    if(prices.size() == 0)
        return 0;
        
    int profit = 0;
    int minNum = prices[0];
    
    for(int i = 1; i < prices.size(); i++) {
        profit = max(profit, prices[i] - minNum); // to calculate the current max profit(p[i] - min)
        minNum = min(minNum, prices[i]);     //record the minest
    }
    return profit;
}


int main(int argc, char *argv[]) {
    vector<int> v;

    v.push_back(12);
    v.push_back(22);
    v.push_back(18);
    v.push_back(28);

    cout<<maxProfit(v)<<endl;

    return 0;
}

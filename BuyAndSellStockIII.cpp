#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int maxProfit(vector<int> &prices) {

    if(prices.size() == 0)
        return 0;

    int *local = new int[3];
    int *global = new int[3];

    for(int i = 0; i < 3; i++){
        global[i] = 0;
        local[i] = 0;
    }

    for(int i = 0; i < prices.size() - 1; i++) {
        int diff = prices[i + 1] - prices[i];
        for(int j = 2; j >= 1; j--) {
            local[j] = max(global[j - 1] + (diff > 0 ? diff : 0), local[j] + diff);
            global[j] = max(global[j], local[j]);
        }
    }

    return global[2];
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

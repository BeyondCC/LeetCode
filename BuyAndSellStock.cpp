#include<iostream>

using namespace std;

int maxProfit(vector<int> &prices) {
    int size = prices.size();
    int *dp = new int[size];

    for(int i = 0; i < size; i++) {
        dp[i] = 0;
    }

    for(int i = 1; i < size; i++) {
        dp[i] 
    }

    return dp[size - 1];
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

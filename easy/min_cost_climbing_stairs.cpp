#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int recurse(int i, vector<int> &cost, vector<int> &dp){
    if(i >= cost.size()) return 0;
    if(dp[i] != -1) return dp[i];
    dp[i] = cost[i] + min(recurse(i + 1, cost, dp), recurse(i + 2, cost, dp));
    return dp[i];
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(cost.size() + 2);
    for(int i = n - 1; i >= 0; i--){
        dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
    }
    return min(dp[0], dp[1]);
}

void solve(){
    int n;
    cin >> n;
    vector<int> cost(n);
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    cout << minCostClimbingStairs(cost);
}

int main(void){
    solve();
    return 1;
}
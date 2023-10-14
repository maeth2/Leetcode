#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int recurse(int i, int j, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp){
    if(j <= 0) return 0;
    if(i == cost.size()) return 1e9;
    if(dp[i][j] != 0) return dp[i][j];
    int a = cost[i] + recurse(i + 1, j - 1 - time[i], cost, time, dp);
    int b = recurse(i + 1, j, cost, time, dp);
    dp[i][j] = min(a, b);
    return dp[i][j];
}

int paintWalls(vector<int>& cost, vector<int>& time) {
    int n = cost.size();
    vector<vector<int>> dp(cost.size() + 1,vector<int>(cost.size() + 1));
    for(int i = 1; i <= n; i++) dp[n][i] = 1e9;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; j <= n; j++){
            int a = cost[i] + dp[i + 1][max(0, j - 1 - time[i])];
            int b = dp[i + 1][j];
            dp[i][j] = min(a, b);
        }
    }
    return dp[0][n];
}

void solve(){
    int n;
    cin >> n;
    vector<int> cost(n);
    vector<int> time(n);
    for(int i = 0; i < n; i++) cin >> cost[i];
    for(int i = 0; i < n; i++) cin >> time[i];
    cout << paintWalls(cost, time);
}

int main(void){
    solve();
    return 1;
}
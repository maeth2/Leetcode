#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int recurse(int i, bool buy, int sales, vector<int> &prices, vector<vector<vector<int>>> &dp){
    if(i == prices.size()) return 0;
    if(sales == 0) return 0;
    if(dp[i][buy][sales] != -1) return dp[i][buy][sales];
    int ans = 0;
    ans = recurse(i + 1, buy, sales, prices, dp);
    if(buy){
        ans = max(ans, recurse(i + 1, false, sales, prices, dp) - prices[i]);
    }else{
        ans = max(ans, prices[i] + recurse(i + 1, true, sales - 1, prices, dp));
    }
    dp[i][buy][sales] = ans;
    return ans;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3)));
    for(int s = 1; s <= 2; s++){
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= 1; j++){
                int ans = 0;
                ans = dp[i + 1][j][s];
                if(j){
                    ans = max(ans, dp[i + 1][0][s] - prices[i]);
                }else{
                    ans = max(ans, prices[i] + dp[i + 1][1][s - 1]);
                }
                dp[i][j][s] = ans;
            }
        }
    }
    return dp[0][1][2];
}

void solve(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << maxProfit(prices);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int mx = 1e9 + 7;

int recurse(int i, int s, int len, vector<vector<int>> &dp){
    if(i < 0 || i == len) return 0;
    if(s == 0) return i == 0;
    if(dp[i][s] != -1) return dp[i][s];
    int a = recurse(i - 1, s - 1, len, dp);
    a = (a + recurse(i + 1, s - 1, len, dp)) % mx;
    a = (a + recurse(i, s - 1, len, dp)) % mx;
    return dp[i][s] = a;
}

int numWays(int steps, int arrLen) {
    int n = min(steps, arrLen);
    vector<vector<int>> dp(steps + 1, vector<int>(steps + 1));
    dp[0][0] = 1;
    for(int j = 1; j <= steps; j++){
        for(int i = steps - 1; i >= 0; i--){
            int s = dp[i][j - 1];
            if(i > 0) s = (s + dp[i - 1][j - 1]) % mx;
            if(i < arrLen - 1) s = (s + dp[i + 1][j - 1]) % mx;
            dp[i][j] = s;
        }
    }
    return dp[0][steps];
}

void solve(){
    int steps, arrLen;
    cin >> steps >> arrLen;
    cout << numWays(steps, arrLen);
}

int main(void){
    solve();
    return 1;
}
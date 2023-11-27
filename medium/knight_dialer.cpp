#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int MOD = 1e9 + 7;

long recurse(int r, int c, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    if(r >= 4 || r < 0 || c >= 3 || c < 0) return 0;
    if(grid[r][c]) return 0;
    if(n == 1) return 1;
    if(dp[n][r][c] != -1) return dp[n][r][c];
    long ans = 0;
    ans = (ans + recurse(r - 2, c + 1, n - 1, grid, dp)) % MOD;
    ans = (ans + recurse(r - 2, c - 1, n - 1, grid, dp)) % MOD;
    ans = (ans + recurse(r + 2, c + 1, n - 1, grid, dp)) % MOD;
    ans = (ans + recurse(r + 2, c - 1, n - 1, grid, dp)) % MOD;
    ans = (ans + recurse(r + 1, c - 2, n - 1, grid, dp)) % MOD;
    ans = (ans + recurse(r - 1, c - 2, n - 1, grid, dp)) % MOD;
    ans = (ans + recurse(r + 1, c + 2, n - 1, grid, dp)) % MOD;
    ans = (ans + recurse(r - 1, c + 2, n - 1, grid, dp)) % MOD;
    dp[n][r][c] = ans;
    return ans;
}

int knightDialer(int n) {
    vector<vector<int>> grid {{0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},
                            {1, 0, 1}};
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(4, vector<int>(3, -1)));
    long ans = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            ans = (ans + recurse(i, j, n, grid, dp)) % MOD;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    cout << knightDialer(n);
}

int main(void){
    solve();
    return 1;
}
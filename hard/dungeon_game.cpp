#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

int recurse(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& dp){
    int n = dungeon.size();
    int m = dungeon[0].size();
    if(i == n || j == m) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];
    if(i == n - 1 && j == m - 1) return (dungeon[i][j] <= 0 ? -dungeon[i][j] + 1: 1);
    int a = recurse(i + 1, j, dungeon, dp);
    int b = recurse(i, j + 1, dungeon, dp);
    int ans = min(a, b) - dungeon[i][j];
    dp[i][j] = ans <= 0 ? 1 : ans;
    return dp[i][j];
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), -1));
    return recurse(0, 0, dungeon, dp);
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dungeon(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> dungeon[i][j];
        }
    }
    cout << calculateMinimumHP(dungeon);
}

int main(void){
    solve();
    return 1;
}
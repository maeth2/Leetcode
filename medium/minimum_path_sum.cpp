#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;
using ll = long long;

template <typename T> 
void print(vector<vector<T>> a){
    for(vector<T> i : a){
        for(T j : i){
            cout << j << ' ';
        }
        cout << "\n";
    }
    cout << "\n";
}

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT32_MAX));
    dp[n - 1][m - 1] = grid[n - 1][m - 1];
    for(int r = n - 1; r >= 0; r--){
        for(int c = m - 1; c >= 0; c--){
            if(r == n - 1 && c == m - 1) continue;
            int left = dp[r][c + 1];
            int down = dp[r + 1][c];
            dp[r][c] = grid[r][c] + min(left, down);
        }
    }
    return dp[0][0];
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    cout << minPathSum(grid);
}

int main(void){
    solve();
    return 1;
}
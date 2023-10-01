#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

/*
    NOTE: Restraints are very small, 1 <= m * n <= 20. No need to do anything fancy just a simple DFS will work.
*/
void recurse(int r, int c, int &ans, int count, vector<vector<int>> &grid){
    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return;
    if(grid[r][c] == -1) return;
    if(grid[r][c] == 2){
        if(count == 1) ans++;
        return;
    }
    int temp = grid[r][c];
    grid[r][c] = -1;
    recurse(r + 1, c, ans, count - 1, grid);
    recurse(r - 1, c, ans, count - 1, grid);
    recurse(r, c + 1, ans, count - 1, grid);
    recurse(r, c - 1, ans, count - 1, grid);
    grid[r][c] = temp;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    int startr = -1, startc = -1;
    int count = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 1){
                startr = i;
                startc = j;
            }
            if(grid[i][j] != -1){
                count++;
            }
        }
    }
    int ans = 0;
    recurse(startr, startc, ans, count, grid);
    return ans;
}

void solve(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    cout << uniquePathsIII(grid);
}

int main(void){
    solve();
    return 1;
}
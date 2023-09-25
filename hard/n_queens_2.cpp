#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int recurse(int n, int r, vector<vector<bool>> dir){
    if(r == n){
        return 1;
    }
    int ans = 0;
    for(int c = 0; c < n; c++){
        bool safe = true;
        safe = !dir[0][r] && !dir[1][c] && !dir[2][r + c] && !dir[3][r + n - c - 1];
        if(!safe) continue;
        dir[0][r] = true;
        dir[1][c] = true;
        dir[2][r + c] = true;
        dir[3][r + n - c - 1] = true;
        ans += recurse(n, r + 1, dir);
        dir[0][r] = false;
        dir[1][c] = false;
        dir[2][r + c] = false;
        dir[3][r + n - c - 1] = false;
    }
    return ans;
}

int totalNQueens(int n) {
    vector<vector<bool>> dir(4, vector<bool>(n * 2));
    return recurse(n, 0, dir);
}

void solve(){
    int n;
    cin >> n;
    cout << totalNQueens(n);
}

int main(void){
    solve();
    return 1;
}
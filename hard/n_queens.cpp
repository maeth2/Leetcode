#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
/*
    No Backtracking
    void recurse(int n, int r, int c, vector<vector<bool>> dir, vector<string> pos, vector<vector<string>> &ans){
        bool safe = true;
        safe = !dir[0][r] && !dir[1][c] && !dir[2][r + c] && !dir[3][r + n - c - 1];
        if(safe){
            pos[r][c] = 'Q';
            if(r != n - 1){
                dir[0][r] = true;
                dir[1][c] = true;
                dir[2][r + c] = true;
                dir[3][r + n - c - 1] = true;
                for(int i = 0; i < n; i++){
                    recurse(n, r + 1, i, dir, pos, ans);
                }
            }else{
                ans.push_back(pos);
            }    
        }
    }
*/
void recurse(int n, int r, vector<vector<bool>> dir, vector<string> pos, vector<vector<string>> &ans){
    if(r == n){
        ans.push_back(pos);
        return;
    }
    for(int c = 0; c < n; c++){
        bool safe = true;
        safe = !dir[0][r] && !dir[1][c] && !dir[2][r + c] && !dir[3][r + n - c - 1];
        if(!safe) continue;
        pos[r][c] = 'Q';
        dir[0][r] = true;
        dir[1][c] = true;
        dir[2][r + c] = true;
        dir[3][r + n - c - 1] = true;
        recurse(n, r + 1, dir, pos, ans);
        pos[r][c] = '.';
        dir[0][r] = false;
        dir[1][c] = false;
        dir[2][r + c] = false;
        dir[3][r + n - c - 1] = false;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<vector<bool>> dir(4, vector<bool>(n * 2));
    vector<string> pos(n);
    string r;
    for(int i = 0; i < n; i++){
        r += '.';
    }
    for(int i = 0; i < n; i++){
        pos[i] = r;
    }
    recurse(n, 0, dir, pos, ans);
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<string>> ans = solveNQueens(n);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << '\n';
        }
        cout << "\n";
    }
}

int main(void){
    solve();
    return 1;
}
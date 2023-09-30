#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

/*
    USING A WAVE COLLAPSE ALGORITHM
*/
bool propogate(int r, int c, char val, vector<vector<string>> &cell){ 
    cell[r][c] = val;
    for(int i = 0; i < 9; i++){
        if(i != r){
            int index = cell[i][c].find(val);
            if(index != std::string::npos && cell[i][c].length() == 1) return false;
            if(index != std::string::npos){
                cell[i][c].erase(index, 1);
            }
        }
        if(i != c){
            int index = cell[r][i].find(val);
            if(index != std::string::npos && cell[r][i].length() == 1) return false;
            if(index != std::string::npos){
                cell[r][i].erase(index, 1);
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int r1 = r / 3 * 3 + i;
            int c1 = c / 3 * 3 + j;
            if(r1 == r || c1 == c) continue;
            int index = cell[r1][c1].find(val);
            if(index != std::string::npos && cell[r1][c1].length() == 1) return false;
            if(index != std::string::npos){
                cell[r1][c1].erase(index, 1);
            }
        }
    }
    return true;
}

vector<int> findSmallest(vector<vector<string>> cell, vector<vector<bool>> collapsed){
    int mn = INT32_MAX;
    int mr, mc;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int length = cell[i][j].length();
            if(length < mn && !collapsed[i][j]){
                mr = i;
                mc = j;
                mn = length;
            }
        }
    }
    if(mn == INT32_MAX) mn = -1;
    vector<int> ans = {mr, mc, mn};
    return ans;
}

bool recurse(vector<vector<string>> cell, vector<vector<bool>> collapsed, vector<vector<char>> &board){
    vector<int> n = findSmallest(cell, collapsed);
    int r = n[0];
    int c = n[1];
    int l = n[2];
    if(l == -1){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                board[i][j] = cell[i][j][0];
            }
        }
        return true;
    }
    for(char val : cell[r][c]){
        vector<vector<string>> c2 = cell;
        if(propogate(r, c, val, c2)){
            collapsed[r][c] = true;
            if(recurse(c2, collapsed, board)) return true;
            collapsed[r][c] = false;
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    vector<vector<string>> cell(9, vector<string>(9, "123456789"));
    vector<vector<bool>> collapsed(9, vector<bool>(9));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char c = board[i][j];
            if(c == '.') continue;
            propogate(i, j, c, cell);
        }
    }
    recurse(cell, collapsed, board);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << ' ';
        }
        cout << "\n";
    }
}

void solve(){
    vector<vector<char>> board(9, vector<char>(9));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
        }
    }
    solveSudoku(board);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool recurse(int r, int c, vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<bool>> &grp, vector<vector<char>> &board){
    if(c == 9){
        c = 0;
        r++;
    }
    if(r == 9){
        return true;
    }
    if(board[r][c] == '.'){
        for(int i = 1; i < 10; i++){
            if(!row[r][i] && !col[c][i] && !grp[r / 3 * 3 + c / 3][i]){
                row[r][i] = true;
                col[c][i] = true;
                grp[r / 3 * 3 + c / 3][i] = true;
                board[r][c] = i + '0';
                if(recurse(r, c + 1, row, col, grp, board)) return true;
                row[r][i] = false;
                col[c][i] = false;
                grp[r / 3 * 3 + c / 3][i] = false;
                board[r][c] = '.';
            }
        }
    }else{
        if(recurse(r, c + 1, row, col, grp, board)) return true;
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> row(9, vector<bool>(10));
    vector<vector<bool>> col(9, vector<bool>(10));
    vector<vector<bool>> grp(9, vector<bool>(10));

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char c = board[i][j];
            if(board[i][j] == '.') continue;
            row[i][c - '0'] = true;
            col[j][c - '0'] = true;
            grp[i / 3 * 3 + j / 3][c - '0'] = true;
        }
    }

    recurse(0, 0, row, col, grp, board);
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
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> tower(query_row + 1, vector<double>(query_row + 1));
    tower[0][0] = poured;
    for(int i = 1; i <= query_row; i++){
        for(int j = 0; j <= query_row; j++){
            double left = 0;
            double right = 0;
            if(j != 0) left = (tower[i - 1][j - 1] - 1) / 2.0;
            right = (tower[i - 1][j] - 1) / 2.0;
            left = left > 0 ? left : 0;
            right = right > 0 ? right : 0;
            tower[i][j] =  left + right;    
        }
    }
    return tower[query_row][query_glass] > 1 ? 1 : tower[query_row][query_glass];
}

void solve(){
    int n, r, c;
    cin >> n >> r >> c;
    cout << champagneTower(n, r, c);
}

int main(void){
    solve();
    return 1;
}
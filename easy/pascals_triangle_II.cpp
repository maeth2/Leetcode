#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<int> getRow(int rowIndex) {
    vector<vector<int>> dp(rowIndex + 1, vector<int>(rowIndex + 1));
    dp[0][0] = 1;
    for(int i = 1; i <= rowIndex; i++){
        for(int j = 0; j <= i; j++){
            if(j <= i - 1) dp[i][j] += dp[i - 1][j];
            if(j > 0) dp[i][j] += dp[i - 1][j - 1];
        }
    }
    return dp[rowIndex];
}

void solve(){
    int rowIndex;
    cin >> rowIndex;
    vector<int> ans = getRow(rowIndex);
    for(int i : ans) cout << i << ' ';
}

int main(void){
    solve();
    return 1;
}
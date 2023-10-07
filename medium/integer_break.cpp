#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int recurse(int num, int k, vector<int> &dp){
    if(num == 0){
        if(k < 2) return 0;
        return 1;
    }
    if(dp[num] != -1) return dp[num];
    for(int i = num; i > 0; i--){
        dp[num] = max(dp[num], i * recurse(num - i, k + 1, dp));
    }
   return dp[num];
}

int recurse1(int num, int k, int j, vector<int> &dp){
    if(num == 0){
        if(k < 2) return 0;
        return 1;
    }
    if(dp[num] != -1) return dp[num];
    int a = 0;
    int b = 0;
    if(j > 0) a = j * recurse1(num - j, k + 1, 0, dp);
    if(j + 1 <= num) b = recurse1(num, k, j + 1, dp);
    dp[num] = max(a, b);
    return dp[num];
}

int integerBreak(int n) {
    vector<int> dp(n + 1, -1);
    return recurse(n, 0, dp);
}

void solve(){
    int n;
    cin >> n;
    cout << integerBreak(n);
}

int main(void){
    solve();
    return 1;
}
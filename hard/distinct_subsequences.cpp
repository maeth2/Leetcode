#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int recurse(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(j == t.size()) return 1;
    if(i == s.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if(s[i] == t[j]) ans += recurse(i + 1, j + 1, s, t, dp);
    ans += recurse(i + 1, j, s, t, dp);
    dp[i][j] = ans;
    return ans;
}

int numDistinct(string s, string t) {
    vector<vector<unsigned>> dp(s.size() + 1, vector<unsigned>(t.size() + 1));
    for(int i = 0; i <= s.size(); i++){
        dp[i][t.size()] = 1;
    }
    for(int i = s.size() - 1; i >= 0; i--){
        for(int j = t.size() - 1; j >= 0; j--){
            if(s[i] == t[j]) dp[i][j] += dp[i + 1][j + 1];
            dp[i][j] += dp[i + 1][j];
        }
    }
    return dp[0][0];
}

void solve(){
    string s, t;
    cin >> s >> t;
    cout << numDistinct(s, t);
}

int main(void){
    solve();
    return 1;
}
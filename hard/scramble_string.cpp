#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool recurse(int i, int j, int l, string s1, string s2, vector<vector<vector<int>>> &dp){
    if(dp[l][i][j] != -1) return dp[l][i][j];
    if(l == 1) return s1[i] == s2[j];
    for(int k = 1; k < l; k++){
        if(recurse(i, j, k, s1, s2, dp) && recurse(i + k, j + k, l - k, s1, s2, dp)) return dp[l][i][j] = true;
        if(recurse(i, j + l - k, k, s1, s2, dp) && recurse(i + k, j, l - k, s1, s2, dp)) return dp[l][i][j] = true;
    }
    return dp[l][i][j] = false;
}

bool isScramble(string s1, string s2) {
    vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s1.size() + 1, vector<int>(s1.size() + 1, - 1)));
    return recurse(0, 0, s1.length(), s1, s2, dp);
}

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << isScramble(s1, s2);
}

int main(void){
    solve();
    return 1;
}
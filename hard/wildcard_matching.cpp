#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, 0));
    for(int i = s.length(); i >= 0 ; i--){
        for(int j = p.length(); j >= 0 ; j--){
            if(i == s.length() && j == p.length()){
                dp[i][j] = true;
            }else if(i == s.length()){
                if(p[j] == '*'){
                    dp[i][j] = dp[i][j + 1];
                }else{
                    dp[i][j] = false;
                }
            }else if(j == p.length()){
                dp[i][j] = false;
            }else if(p[j] == '*'){
                dp[i][j] = dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j + 1];
            }else if(p[j] == '?' || s[i] == p[j]){
                dp[i][j] = dp[i + 1][j + 1];
            }else{
                dp[i][j] = false;
            }
        }
    }
    return dp[0][0];
}

void solve(){
    string s, p;
    cin >> s >> p;
    cout << isMatch(s, p);
}

int main(void){
    solve();
    return 1;
}
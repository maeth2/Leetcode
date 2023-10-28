#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int MOD = 1e9 + 7;

long recurse(int i, char j, vector<vector<int>> &dp){
    long ans = 0;
    if(dp[j - 'a'][i] != -1) return dp[j - 'a'][i];
    if(i == 0) return 0;
    if(j == 'e' || j == 'u' || j == 'i')    ans = (ans + recurse(i - 1, 'a', dp)) % MOD;
    if(j == 'a' || j == 'i')                ans = (ans + recurse(i - 1, 'e', dp)) % MOD;
    if(j == 'e' || j == 'o')                ans = (ans + recurse(i - 1, 'i', dp)) % MOD;
    if(j == 'i')                            ans = (ans + recurse(i - 1, 'o', dp)) % MOD;
    if(j == 'o' || j == 'i')                ans = (ans + recurse(i - 1, 'u', dp)) % MOD;
    dp[j - 'a'][i] = ans == 0 ? 1 : ans;
    return dp[j - 'a'][i];
}
int countVowelPermutation(int n) {
    vector<vector<int>> dp(26, vector<int>(n + 1, -1));
    int ans = 0;
    ans = (ans + recurse(n, 'a', dp)) % MOD;
    ans = (ans + recurse(n, 'e', dp)) % MOD;
    ans = (ans + recurse(n, 'i', dp)) % MOD;
    ans = (ans + recurse(n, 'o', dp)) % MOD;
    ans = (ans + recurse(n, 'u', dp)) % MOD;
    return ans;
}

void solve(){
    int n;
    cin >> n;
    cout << countVowelPermutation(n);
}   

int main(void){
    solve();
    return 1;
}
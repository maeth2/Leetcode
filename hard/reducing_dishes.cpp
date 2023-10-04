#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int maxSatisfactionTopDown(vector<int>& satisfaction) {
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
    sort(satisfaction.begin(), satisfaction.end());
    for(int i = 1; i <= n + 1; i++){
        dp[n][i] = 0;
    }
    for(int i = n - 1; i >= 0; i--){
        for(int j = n; j > 0; j--){
            int a = j * satisfaction[i] + dp[i + 1][j + 1];
            int b = dp[i + 1][j];
            dp[i][j] = max(a, b);
        }
    }
    return dp[0][1];
}

int recurse(int i, int count, vector<int>& satisfaction, vector<vector<int>> &dp){
    if(i == satisfaction.size()) return 0;
    if(dp[i][count] != -1) return dp[i][count];
    int a = count * satisfaction[i] + recurse(i + 1, count + 1, satisfaction, dp);
    int b = recurse(i + 1, count, satisfaction, dp);
    dp[i][count] = max(a, b);
    return dp[i][count];
}

int maxSatisfactionBottomUp(vector<int>& satisfaction) {
    vector<vector<int>> dp(satisfaction.size(), vector<int>(satisfaction.size() + 1, -1));
    sort(satisfaction.begin(), satisfaction.end());
    return recurse(0, 1, satisfaction, dp);
}

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();
    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += (j - i + 1) * satisfaction[j];
        }
        ans = max(sum, ans);
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> satisfaction(n);
    for(int i = 0; i < n; i++){
        cin >> satisfaction[i];
    }
    cout << maxSatisfaction(satisfaction);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

long MOD_MAX = 1e9 + 7;

/*
    NOTE: We are given an array of positive numbers. The condition of the array is that its size is n, the largest number is m, and for every 
    instance of a new maximum in the array, a cost will be added. The cost by the end of the array must equal to k.

    To solve this, we can recursively add numbers into an array and update the cost. Once we have added n numbers, we check if the cost is equal to k.

    We can do this by following these 2 cases:
        1. If the next number we add is less than the current maximum, we will not increase the cost, the Maximum will stay the same
        2. If the next number is greather than the current Maximum, we will increase the cost and update the Maximum.
*/

long recurse(int &n, int &m, int curr, int maxNum, int cost, vector<vector<vector<long>>> &dp){
    if(n == curr) return cost == 0;
    if(cost < 0) return 0;
    if(dp[curr][maxNum][cost] != -1) return dp[curr][maxNum][cost];
    long ans = 0;
    for(int i = 1; i <= m; i++){
        ans = (ans + recurse(n, m, curr + 1, max(i, maxNum), cost - (i > maxNum ? 1 : 0), dp)) % MOD_MAX;
    }
    dp[curr][maxNum][cost] = ans;
    return dp[curr][maxNum][cost];
}

int numOfArrays(int n, int m, int k) {
    vector<vector<vector<long>>> dp(n + 1, vector<vector<long>>(m + 1, vector<long>(k + 1, -1)));
    return recurse(n, m, 0, 0, k, dp);
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    cout << numOfArrays(n, m, k);
}

int main(void){
    solve();
    return 1;
}
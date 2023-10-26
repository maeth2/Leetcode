#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int MOD = 1e9 + 7;

long recurse(int val, vector<int> &arr, map<int, long> &dp){
    if(dp[val] != -1) return dp[val];
    long ans = 0;
    for(int i : arr){
        if(i > sqrt(val)) break;
        if(val % i == 0){
            if(dp.find(val / i) != dp.end()){
                long a = 0;
                if(val / i == i){
                    a = recurse(i, arr, dp);
                    a = (a * a) % MOD;
                }else{ 
                    a = (recurse(i, arr, dp) * recurse(val / i, arr, dp) * 2) % MOD;
                }
                ans = (ans + a) % MOD;
            }
        }
    }
    dp[val] = (ans + 1) % MOD;
    return dp[val];
}

int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    map<int, long> dp;
    for(int i : arr) dp[i] = -1;
    int ans = 0;
    for(int i : arr){
        ans = (ans + recurse(i, arr, dp)) % MOD;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << numFactoredBinaryTrees(arr);
}

int main(void){
    solve();
    return 1;
}
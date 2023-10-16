#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int recurse(int target, vector<int> &nums, vector<int> &dp){
    if(target == 0) return 1;
    if(target < 0) return 0;
    if(dp[target] != -1) return dp[target];
    int total = 0;
    for(int i : nums){
        total += recurse(target - i, nums, dp);
    }
    dp[target] = total;
    return dp[target];
}

int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned> dp(target + 1);
    dp[0] = 1;
    for(int i = 1; i <= target; i++){
        int total = 0;
        for(int j : nums){
            int ni = i - j;
            if(ni >= 0) total += dp[ni];
        }
        dp[i] = total;
    }
    return dp[target];
}

void solve(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << combinationSum4(nums, target);
}

int main(void){
    solve();
    return 1;
}
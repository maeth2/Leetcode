#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;

int MOD = 1e9 + 7;

int reverse(int n){
    int ans = 0;
    while(n != 0){
        int i = n % 10;
        ans = ans * 10 + i;
        n /= 10;
    }
    return ans;
}

int countNicePairs(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    map<int, int> searched;
    for(int i = 0; i < n; i++){
        int j = nums[i] - reverse(nums[i]);
        if(searched[j]) ans = (ans + searched[j]) % MOD;
        else searched[j] = 0;
        searched[j]++;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << countNicePairs(nums);
}

int main(void){
    solve();
    return 1;
}
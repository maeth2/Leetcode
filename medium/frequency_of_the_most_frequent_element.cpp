#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;
using ll = long long;

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long total = 0;
    int j = 0;
    int ans = 0;

    for(int i = 0; i < n; i++){
        long t = nums[i]; //Prevents int overflow
        total += nums[i];
        while(t * (i - j + 1) - total > k){
            total -= nums[j];
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << maxFrequency(nums, k);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int minPairSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = INT_MIN;
    for(int i = 0; i < nums.size() / 2; i++){
        ans = max(ans, nums[i] + nums[n - i - 1]);
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << minPairSum(nums);
}

int main(void){
    solve();
    return 1;
}
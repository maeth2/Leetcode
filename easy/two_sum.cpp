#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> dp;
    vector<int> ans(2);
    for(int i = 0; i < nums.size(); i++){
        int difference = target - nums[i];
        if(dp.find(nums[i]) != dp.end()){
            ans[0] = i;
            ans[1] = dp[nums[i]];
            break;
        }else{
            dp[difference] = i;
        }
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for(int i : twoSum(nums, m)){
        cout << i << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
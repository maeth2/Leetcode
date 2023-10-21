#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

int constrainedSubsetSum(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    pq.emplace(nums[0], 0);
    int ans = nums[0];
    for(int i = 1; i < nums.size(); i++){
        while(pq.top().second > k){
            pq.pop();
        }
        int curr = max(0, pq.top().first) + nums[i];
        ans = max(ans, curr);
        pq.emplace(curr, i);
    }
    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << constrainedSubsetSum(nums, k);
}

int main(void){
    solve();
    return 1;
}
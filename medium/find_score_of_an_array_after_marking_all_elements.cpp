#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

long long findScore(vector<int>& nums) {
    vector<pair<int, int>> sorted;
    for(int i = 0; i < nums.size(); i++){
        sorted.push_back(make_pair(nums[i], i));
    }
    sort(sorted.begin(), sorted.end());
    vector<bool> searched(nums.size());
    long long ans = 0;
    for(int i = 0; i < sorted.size(); i++){
        int index = sorted[i].second;
        if(!searched[index]){
            searched[index] = true;
            if(index - 1 >= 0) searched[index - 1] = true;
            if(index + 1 < nums.size()) searched[index + 1] = true;
            ans += nums[index];
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << findScore(nums);
}

int main(void){
    solve();
    return 1;
}
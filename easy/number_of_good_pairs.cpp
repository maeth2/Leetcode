#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int numIdenticalPairs(vector<int>& nums) {
    int ans = 0;
    vector<int> searched(100);
    for(int i = 0; i < nums.size(); i++){
        if(searched[nums[i] - 1]) ans += searched[nums[i] - 1];
        searched[nums[i] - 1]++;
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
    cout << numIdenticalPairs(nums);
}

int main(void){
    solve();
    return 1;
}
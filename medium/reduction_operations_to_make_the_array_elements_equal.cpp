#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int reductionOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> count;
    int n = nums.size();
    int prev = nums[0];
    int c = 0;

    for(int i = 0; i < nums.size(); i++){
        int v = nums[i];
        if(prev != v){
            count.push_back(c);
            c = 0;
        }
        prev = v;
        c++;
    }
    count.push_back(c);

    int ans = 0;
    int prevTotal = 0;
    for(int i = count.size() - 1; i >= 1; i--){
        prevTotal += count[i];
        ans += prevTotal;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << reductionOperations(nums);
}

int main(void){
    solve();
    return 1;
}
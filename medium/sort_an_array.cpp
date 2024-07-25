#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<int> sortArray(vector<int>& nums) {
    vector<int> ans;
    for(int i : nums){
        int l = 0;
        int r = ans.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(i >= ans[m]){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        ans.insert(ans.begin() + l, i);
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
    vector<int> ans = sortArray(nums);
    for(int i : ans){
        cout << i << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool check(vector<int> a){
    if(a.size() == 1) return true;
    sort(a.begin(), a.end());
    int diff = a[1] - a[0];
    for(int i = 2; i < a.size(); i++){
        if(diff != a[i] - a[i - 1]) return false;
    }
    return true;
}

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int n = nums.size();
    int m = l.size();
    vector<bool> ans;
    for(int i = 0; i < m; i++){
        ans.push_back(check(vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1)));
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    vector<int> l(m);
    vector<int> r(m);
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 0; i < m; i++) cin >> l[i];
    for(int i = 0; i < m; i++) cin >> r[i];
    vector<bool> ans = checkArithmeticSubarrays(nums, l, r);
    for(bool i : ans) cout << i << " ";
}

int main(void){
    solve();
    return 1;
}
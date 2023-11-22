#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int n = nums.size();
    map<int, vector<int>> mp;
    int m = 0;
    for(int i = n - 1; i >= 0; i--){
        m = m > nums[i].size() ? m : nums[i].size();
        for(int j = 0; j < nums[i].size(); j++){
            mp[i + j].push_back(nums[i][j]);
        }
    }
    vector<int> ans;
    for(int i = 0; i < n + m; i++){
        for(int j : mp[i]){
            ans.push_back(j);
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> nums(n);
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int v;
            cin >> v;
            nums[i].push_back(v);
        }
    }
    vector<int> ans = findDiagonalOrder(nums);
    for(int i : ans) cout << i << ' ';
}

int main(void){
    solve();
    return 1;
}
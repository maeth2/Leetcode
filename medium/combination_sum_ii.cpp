#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void recurse(int i, int target, vector<int> curr, vector<int>& candidates, vector<vector<int>>& ans){
    int v = target - candidates[i];
    if(v < 0) return;
    curr.push_back(candidates[i]);
    if(v == 0){
        ans.push_back(curr);
        return;
    }
    int prev = -1;
    for(int j = i + 1; j < candidates.size(); j++){
        if(prev == candidates[j]) continue;
        recurse(j, v, curr, candidates, ans);
        prev = candidates[j];
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    int prev = -1;
    for(int i = 0; i < candidates.size(); i++){
        if(prev == candidates[i]) continue;
        recurse(i, target, {}, candidates, ans);
        prev = candidates[i];
    }
    return ans;
}

void solve(){
    int n, target;
    cin >> n >> target;
    vector<int> candidates(n);
    for(int i = 0; i < n; i++){
        cin >> candidates[i];
    }
    vector<vector<int>> ans = combinationSum2(candidates, target);
    for(vector<int> i : ans){
        for(int j : i){
            cout << j << ' ';
        }
        cout << "\n";
    }
}

int main(void){
    solve();
    return 1;
}
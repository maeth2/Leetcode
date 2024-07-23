#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;

vector<int> frequencySort(vector<int>& nums) {
    map<int, int> mp;
    for(int i : nums){  
        mp[i]++;
    }
    map<int, int>::iterator it;
    vector<pair<int, int>> fp;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        fp.emplace_back(it->first, it->second);   
    }
    sort(fp.begin(), fp.end(),
    [&](pair<int, int> &a, pair<int, int> &b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second < b.second;
    });
    vector<int> ans;
    for(pair<int, int> i : fp){
        for(int j = 0; j < i.second; j++){
            ans.push_back(i.first);
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
    vector<int> ans = frequencySort(nums);
    for(int i : ans){
        cout << i << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
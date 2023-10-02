#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
using ll = long long;

vector<vector<int>> threeSum2(vector<int>& nums) {
    set<vector<int>> s;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 2; i++){
        int remain = -nums[i];
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == remain){
                s.insert({nums[i], nums[left], nums[right]});
                left++;
            }else if(sum > remain){
                right--;
            }else{
                left++;
            }
        }
    }
    vector<vector<int>> ans;
    for(vector<int> i : s){
        ans.push_back(i);
    }
    return ans;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> s;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 2; i++){
        int remain = -nums[i];
        map<int, int> checked;
        for(int j = i + 1; j < nums.size(); j++){
            int sum = remain - nums[j];
            if(checked.find(sum) != checked.end()){
                s.insert({nums[i], sum, nums[j]});
            }
            checked.emplace(nums[j], 1);
        }
    }
    vector<vector<int>> ans;
    for(vector<int> i : s){
        ans.push_back(i);
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
    vector<vector<int>> ans = threeSum(nums);
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
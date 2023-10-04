#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;
using ll = long long;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    set<vector<int>> setAns;
    int n = nums.size();
    long longTarget = target;
    for(int i = 0; i < n - 3; i++){
        for(int j = i + 1; j < n - 2; j++){
            int t = target - nums[i] - nums[j];
            int l = j + 1;
            int r = n - 1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == t){
                    setAns.insert(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                    do{l++;} while(nums[l] == nums[l - 1] && l < r);
                    do{r--;} while(nums[r] == nums[r + 1] && l < r);
                }else if(sum < t){
                    l++;
                }else{
                    r--;
                }
            }
        }
    }
    vector<vector<int>> ans;
    for(vector<int> i : setAns){
        ans.push_back(i);
    }
    return ans;
}

void solve(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<vector<int>> ans = fourSum(nums, target);
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
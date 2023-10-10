#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int search(int target, vector<int>& nums){
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(nums[middle] == target){
            left = middle;
            break;
        }else if(nums[middle] < target){
            left = middle + 1;
        }else if(nums[middle] > target){
            right = middle - 1;
        }
    }
    return left;
}

int minOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0;
    vector<int> unique;
    unique.push_back(nums[0]);
    int prev = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == prev){
            ans++;
        }else{
            unique.push_back(nums[i]);
        }
        prev = nums[i];
    }

    int mi = INT_MAX;
    int n1 = unique.size();
    for(int i = 0; i < n1; i++){
        int mx = unique[i] + n - 1;
        int index = search(mx, unique);
        if(index < n1 && unique[index] > mx) index--;
        int total = index >= n1 ? i : n1 - index - 1 + i;
        mi = min(mi, total);
    }
    ans += mi;
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << minOperations(nums);
}

int main(void){
    solve();
    return 1;
}
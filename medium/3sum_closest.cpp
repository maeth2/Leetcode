#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    int mi = INT_MAX;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int left = i + 1;
        int right = n - 1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            int a = abs(target - sum);
            if(a < mi){
                mi = a;
                ans = sum;
            }
            if(sum > target){
                right--;
            }else{
                left++;
            }
        }
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
    cout << threeSumClosest(nums, target);
}

int main(void){
    solve();
    return 1;
}
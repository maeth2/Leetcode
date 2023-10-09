#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int index = -1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(nums[middle] == target){
            index = middle;
            break;
        }else if(nums[middle] < target){
            left = middle + 1;
        }else if(nums[middle] > target){
            right = middle - 1;
        }
    }
    if(index == -1) return vector<int>{-1, -1};
    int start = index;
    int end = index;
    for(int i = 1; i <= n / 2; i++){
        if(index - i >= 0 && nums[index - i] == nums[index]){
            start = index - i;
        }
        if(index + i < n && nums[index + i] == nums[index]){
            end = index + i;
        }
    }
    return vector<int>{start, end};
}

void solve(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    nums = searchRange(nums, target);
    for(int i : nums){
        cout << i << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
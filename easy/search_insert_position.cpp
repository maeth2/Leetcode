#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(nums[middle] == target){
            return middle;
        }if(nums[middle] > target){
            right = middle - 1;
        }else{
            left = middle + 1;
        }
    }
    return left;
}

void solve(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << searchInsert(nums, target);
}

int main(void){
    solve();
    return 1;
}
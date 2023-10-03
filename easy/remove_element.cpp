#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int removeElement(vector<int>& nums, int val) {
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == val){
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    return nums.size();
}

void solve(){
    int n, val;
    cin >> n >> val;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int k = removeElement(nums, val);
    cout << k << '\n';
    for(int i = 0; i < k; i++){
        cout << nums[i] << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
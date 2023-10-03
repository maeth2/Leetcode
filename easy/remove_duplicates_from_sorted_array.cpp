#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int removeDuplicates(vector<int>& nums) {
    int index = 0;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[index]){
            index++;
            nums[index] = nums[i]; 
        }
    }
    return index + 1;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int k = removeDuplicates(nums);
    cout << k << '\n';
    for(int i = 0; i < k; i++){
        cout << nums[i] << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
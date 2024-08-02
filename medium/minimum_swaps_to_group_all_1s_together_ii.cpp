#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int slide(int size, int num, vector<int>& nums){
    int c = 0;
    int mx = -1;
    for(int i = 0; i < size; i++){
        if(nums[i] == num){
            c++;
        }
        mx = c;
    }
    for(int i = 0; i < nums.size() - size; i++){
        if(nums[i + size] == num){
            c++;
        }
        if(nums[i] == num){
            c--;
        }
        mx = max(mx, c);
    }
    return mx;
}

int minSwaps(vector<int>& nums) {
    int totalZeros = 0;
    int totalOnes = 0;
    for(int i : nums){
        if(i == 0){
            totalZeros++;
        }else{
            totalOnes++;
        }
    }
    int z = totalZeros - slide(totalZeros, 0, nums);
    int o = totalOnes - slide(totalOnes, 1, nums);
    return min(z, o);
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << minSwaps(nums);
}

int main(void){
    solve();
    return 1;
}
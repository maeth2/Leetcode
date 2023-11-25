#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> sums(n);
    int total = 0;
    for(int i = 0; i < n; i++){
        total += nums[i];
        sums[i] = total;
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int left = (i + 1) * nums[i] - sums[i];
        int right = total - sums[i] - (n - i - 1) * nums[i];
        ans.push_back(left + right);
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    nums = getSumAbsoluteDifferences(nums);
    for(int i : nums) cout << i << ' ';
}

int main(void){
    solve();
    return 1;
}
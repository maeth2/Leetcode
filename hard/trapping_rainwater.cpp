#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int trap(vector<int>& height) {
    int ans = 0;
    int leftMax = INT32_MIN;
    int rightMax = INT32_MIN;
    vector<int> lm(height.size());
    vector<int> rm(height.size());
    for(int i = 0; i < height.size(); i++){
        leftMax = max(leftMax, height[i]);
        rightMax = max(rightMax, height[height.size() - 1 - i]);
        lm[i] = leftMax;
        rm[height.size() - 1 - i] = rightMax;
    }
    for(int i = 0; i < height.size(); i++){
        ans += min(lm[i], rm[i]) - height[i];
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    cout << trap(height);
}

int main(void){
    solve();
    return 1;
}
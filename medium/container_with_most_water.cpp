#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int ans = INT_MIN;
    for(int i = 0; i < height.size(); i++){
        int w = right - left;
        int h = min(height[left], height[right]);
        ans = max(ans, w * h);
        if(height[left] < height[right]){
            left++;
        }else{
            right--;
        }
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
    cout << maxArea(height);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int a, b, c, d;
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            a = i + 1 == n ? INT_MIN : dp[i + 1][j]; //NOT USING CURRENT NUMS MOVE i BY 1
            b = j + 1 == m ? INT_MIN : dp[i][j + 1]; //NOT USING CURRENT NUMS MOVE j BY 1
            c = nums1[i] * nums2[j] + dp[i + 1][j + 1]; //USING CURRENT NUMS, CHECKING OTHER SUBSEQUENCES
            d = nums1[i] * nums2[j]; //USING CURRENT NUMS, NOT CHECKING OTHER SUBSEQUENCES
            dp[i][j] = max(max(a, b), max(c, d));
        }
    }
    return dp[0][0];
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for(int i = 0; i < n; i++){
        cin >> nums1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> nums2[i];
    }
    cout << maxDotProduct(nums1, nums2);
}

int main(void){
    solve();
    return 1;
}
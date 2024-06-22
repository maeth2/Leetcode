#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

int numberOfSubarrays(vector<int>& nums, int k) {
    int ans = 0;
    int n = nums.size();
    vector<int> left(n);
    vector<int> right(n);
    queue<int> st;
    for(int i = 0; i < n; i++){
        bool isEven = nums[i] % 2 == 0;
        if(i == 0){
            left[i] = isEven;
            continue;
        }
        if(isEven){
            left[i] = left[i - 1] + 1;
        }else{
            left[i] = 0;
        }
    }
     for(int i = n - 1; i >= 0; i--){
        bool isEven = nums[i] % 2 == 0;
        if(i == n - 1){
            right[i] = isEven;
            continue;
        }
        if(isEven){
            right[i] = right[i + 1] + 1;
        }else{
            right[i] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        bool isOdd = nums[i] % 2 == 1;
        if(isOdd){
            st.push(i);
        }
        if(st.size() == k){
            int l = st.front() - 1 >= 0 ? left[st.front() - 1] : 0;
            int r = st.back() + 1 < n ? right[st.back() + 1] : 0;
            ans += (l + 1) * (r + 1);
            st.pop();
        }
    }
    return ans;
}

void solve(){
    int n; 
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int k;
    cin >> k;
    cout << numberOfSubarrays(nums, k);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int ans = 1;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] >= ans + 1){
            ans++;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << maximumElementAfterDecrementingAndRearranging(arr);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int countOnes1(int i){
    int ans = 0;
    while(i > 0){
        int a = i % 2;
        if(a == 1) ans++;
        i /= 2;
    }
    return ans;
}

int countOnes(int i){
    int ans = 0;
    int mask = 1;
    while(i > 0){
        if(i & mask){
            ans++;
            i = i ^ mask;
        }
        mask = mask << 1;
    }
    return ans;
}

vector<int> sortByBits(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> bits(14);
    for(int i = 0; i < n; i++){
        bits[countOnes(arr[i])].push_back(arr[i]);
    }
    vector<int> ans;
    for(vector<int> i : bits){
        for(int j : i) ans.push_back(j);
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    arr = sortByBits(arr);
    for(int i : arr) cout << i << " ";
}

int main(void){
    solve();
    return 1;
}
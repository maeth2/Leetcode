#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<long long> arr(n);
    for(int i = 0; i < roads.size(); i++){
        arr[roads[i][0]]++;
        arr[roads[i][1]]++;
    }
    sort(arr.begin(), arr.end());
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += arr[i] * (i + 1);
    }
    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> roads(k, vector<int>(2));
    for(int i = 0; i < k; i++){
        cin >> roads[i][0] >> roads[i][1];
    }
    cout << maximumImportance(n, roads);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<int> findArray(vector<int>& pref) {
    int mask = 0;
    vector<int> ans;
    for(int i : pref){
        int m = i ^ mask;
        ans.push_back(m);
        mask ^= m;
    }
    return ans;
}

void solve(){
    cout << (10 & 12) << "\n";
    int n;
    cin >> n;
    vector<int> pref(n);
    for(int i = 0; i < n; i++) cin >> pref[i];
    pref = findArray(pref);
    for(int i : pref) cout << i << ' ';
}

int main(void){
    solve();
    return 1;
}
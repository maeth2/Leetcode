#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

/*
    NOTE: To solve this problem we have to prove that if a ^ b = c, then a ^ c = b is also true.

    Proof:
    a ^ b = c
    Xor both sides with a.
    a ^ a ^ b = a ^ c
    a ^ a is equal to 0.
    0 ^ b = a ^ c
    b ^ 0 is equal to b.
    b = a ^ c
    Therefore, if a ^ b = c, then a ^ c = b is also true.
    
*/
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
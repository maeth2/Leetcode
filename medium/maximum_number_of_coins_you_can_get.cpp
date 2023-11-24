#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int maxCoins(vector<int>& piles) {
    int n = piles.size();
    sort(piles.begin(), piles.end());
    for(int i : piles) cout << i << ' ';
    cout << "\n";
    int ans = 0;
    for(int i = 0; i < n / 3; i++){
        ans += piles[n - 2 - i * 2];
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> piles(n);
    for(int i = 0; i < n; i++) cin >> piles[i];
    cout << maxCoins(piles);
}

int main(void){
    solve();
    return 1;
}
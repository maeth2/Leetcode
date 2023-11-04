#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int mx = -1;
    for(int i : left){
        mx = max(mx, i);
    }
    for(int i : right){
        mx = max(mx, n - i);
    }
    return mx;
}

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> left(l);
    vector<int> right(r);
    for(int i = 0; i < l; i++) cin >> left[i];
    for(int i = 0; i < r; i++) cin >> right[i];
    cout << getLastMoment(n, left, right);
}

int main(void){
    solve();
    return 1;
}
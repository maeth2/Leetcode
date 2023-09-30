#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

string getPermutation(int n, int k) {
    string ans = "";
    vector<int> a(n);
    int p = 1;
    for(int i = 0; i < n; i++){
        a[i] = i + 1;
        p *= i + 1;
    }
    k--;
    p /= n;
    n--;
    int index = 0;
    while(n > 0){
        index = k / p;
        ans += a[index] + '0';
        a.erase(a.begin() + index);
        k -= index * p;
        p /= n;
        n--;
    }
    ans += a[0] + '0';
    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    cout << getPermutation(n, k);
}

int main(void){
    solve();
    return 1;
}
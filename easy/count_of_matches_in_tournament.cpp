#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int numberOfMatches(int n) {
    int ans = 0;
    while(n > 1){
        bool isEven = n % 2 == 0;
        ans += isEven ? (n / 2) : ((n - 1) / 2);
        n -= isEven ? (n / 2) : ((n - 1) / 2);
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    cout << numberOfMatches(n);
}

int main(void){
    solve();
    return 1;
}
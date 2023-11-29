#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int hammingWeight(uint32_t n) {
    int ans = 0;
    while(n > 0){
        if(n % 2 == 1) ans++;
        n -= n % 2;
        n /= 2;
    }
    return ans;
}

void solve(){
    uint32_t n;
    cin >> n;
    cout << hammingWeight(n);
}

int main(void){
    solve();
    return 1;
}
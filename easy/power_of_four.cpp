#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool isPowerOfFour(int n) {
    return fmod(log2(n), log2(4)) == 0;
}

void solve(){
    int n;
    cin >> n;
    cout << isPowerOfFour(n);
}

int main(void){
    solve();
    return 1;
}
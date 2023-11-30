#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int minimumOneBitOperations(int n) {
    if (n == 0) {
        return 0;
    }
    
    int k = 0;
    int curr = 1;
    while (curr * 2 <= n) {
        curr *= 2;
        k++;
    }
    
    return (1 << (k + 1)) - 1 - minimumOneBitOperations(n ^ curr);
}

void solve(){
    int n;
    cin >> n;
    cout << minimumOneBitOperations(n);
}

int main(void){
    solve();
    return 1;
}
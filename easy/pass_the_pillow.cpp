#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int passThePillow(int n, int time) {
    int tc = time / (n - 1);
    int p = time % (n - 1);
    if(tc % 2 == 0){
        return p + 1;
    }else{
        return n - p;
    }
}

void solve(){
    int n, t;
    cin >> n >> t;
    cout << passThePillow(n, t);
}

int main(void){
    solve();
    return 1;
}
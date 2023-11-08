#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int dist = max(abs(sx - fx), abs(sy - fy));
    if(dist == 0) return t != 1;
    return dist <= t;
}

void solve(){
    int sx, sy, fx, fy, t;
    cin >> sx >> sy >> fx >> fy >> t;
    cout << isReachableAtTime(sx, sy, fx, fy, t);
}

int main(void){
    solve();
    return 1;
}
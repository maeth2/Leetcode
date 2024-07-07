#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int numWaterBottles(int numBottles, int numExchange) {
    int ans = numBottles;
    while(numBottles >= numExchange){
        int swapped = numBottles / numExchange;
        ans += swapped;
        numBottles = swapped + numBottles % numExchange;
    }
    return ans;
}

void solve(){
    int n, e;
    cin >> n >> e;
    cout << numWaterBottles(n, e);
}

int main(void){
    solve();
    return 1;
}
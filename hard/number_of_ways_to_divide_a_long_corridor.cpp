#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int MOD = 1e9 + 7;
int numberOfWays(string corridor) {
    int n = corridor.size();
    long ans = 1;
    int sofas = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(corridor[i] == 'S'){
            sofas++;
        }else if(sofas == 2){
            count++;
        }
        if(sofas > 2){
            ans = (ans * (count + 1)) % MOD;
            sofas = 1;
            count = 0;
        }
    }
    if(sofas != 2) return 0;
    return ans;
}

void solve(){
    string corridor;
    cin >> corridor;
    cout << numberOfWays(corridor);
}

int main(void){
    solve();
    return 1;
}
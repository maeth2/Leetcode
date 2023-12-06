#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int totalMoney(int n) {
    int ans = 0, week = 1, day = 0;
    for(int i = 0; i < n; i++){
        ans += day + week;
        day++;
        if(day == 7){
            day = 0;
            week++;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    cout << totalMoney(n);
}

int main(void){
    solve();
    return 1;
}
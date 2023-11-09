#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int MOD = 1e9 + 7;

int countHomogenous(string s) {
    int n = s.size();
    int count = 0;
    long ans = 0;
    for(int i = 0; i < n; i++){
        if(i == 0 || s[i - 1] == s[i]){
            count++;
        }else{
            count = 1;
        }
        ans = (ans + count) % MOD;
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    cout << countHomogenous(s);
}

int main(void){
    solve();
    return 1;
}
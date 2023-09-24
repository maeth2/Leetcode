#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool isPalindrome(int x) {
    string s = to_string(x);
    for(int i = 0; i < s.length() / 2; i++){
        if(s[i] != s[s.length() - 1 - i]){
            return false;
        }
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    cout << isPalindrome(n);
}

int main(void){
    solve();
    return 1;
}
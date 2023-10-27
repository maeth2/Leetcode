#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

string longestPalindrome(string s) {
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        int l, r;
        for(int j = 0; j <= i; j++){
            l = i - j;
            r = i + j;
            if(r == s.size() || s[l] != s[r]){
                l++;
                r--;
                break;
            }
        }
        if(ans.size() < (r - l + 1)) ans = s.substr(l, (r - l + 1));
        for(int j = 0; j <= i; j++){
            l = i - j;
            r = i + j + 1;
            if(r == s.size() || s[l] != s[r]){
                l++;
                r--;
                break;
            }
        }
        if(ans.size() < (r - l + 1)) ans = s.substr(l, (r - l + 1));
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    cout << longestPalindrome(s);
}

int main(void){
    solve();
    return 1;
}
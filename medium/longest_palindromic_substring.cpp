#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

string check(int i, int j, string s){
    int l, r;
    l = i;
    r = j;
    if(s[l] != s[r]) return "";
    while(l >= 0 && r < s.length()){
        if(s[l] != s[r]) break;
        l--;
        r++;
    }
    l++;
    r--;
    return s.substr(l, r - l + 1);
}

string longestPalindrome(string s) {
    string ans = "";
    if(s.length() <= 1) return s;
    for(int i = 0; i < s.length() - 1; i++){
        string a = check(i, i, s);
        string b = check(i, i + 1, s);
        if(ans.length() < a.length()) ans = a;
        if(ans.length() < b.length()) ans = b;
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
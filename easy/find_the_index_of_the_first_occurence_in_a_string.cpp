#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int strStr(string haystack, string needle) {
    if(haystack.length() < needle.length()) return -1;
    for(int i = 0; i < haystack.length() - (needle.length() - 1); i++){
        if(haystack.substr(i, needle.length()) == needle) return i;
    }
    return -1;
}

void solve(){
    string haystack, needle;
    cin >> haystack >> needle;
    cout << strStr(haystack, needle);
}

int main(void){
    solve();
    return 1;
}
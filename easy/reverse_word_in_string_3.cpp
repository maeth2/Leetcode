#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

string reverse(string s){
    string ans = "";
    for(int i = s.length() - 1; i >= 0; i--){
        ans += s[i];
    }
    return ans;
}

string reverseWords(string s) {
    string ans = "";
    int space = s.find(' ');
    while(space != std::string::npos){
        ans += reverse(s.substr(0, space));
        ans += ' ';
        s.erase(0, space + 1);
        space = s.find(' ');
    }
    ans += reverse(s);
    return ans;
}

void solve(){
    string s;
    cin >> s;
    cout << reverseWords("ABD DEF");
}

int main(void){
    solve();
    return 1;
}
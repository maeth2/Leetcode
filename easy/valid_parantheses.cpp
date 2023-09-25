#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool isValid(string s) {
    string prev;
    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        if(c == '[' || c == '{' || c == '(') prev += c;
        if(prev.length() == 0) return false;
        else if(c == ']'){
            if(prev[prev.length() - 1] != '[') return false;
            prev.pop_back();
        }else if(c == '}'){
            if(prev[prev.length() - 1] != '{') return false;
            prev.pop_back();
        }else if(c == ')'){
            if(prev[prev.length() - 1] != '(') return false;
            prev.pop_back();
        }
    }
    return prev.length() == 0 && true;
}

void solve(){
    string s;
    cin >> s;
    cout << isValid(s);
}

int main(void){
    solve();
    return 1;
}
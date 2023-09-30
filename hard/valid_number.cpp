#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool isDecimal(string s){
    int dot = 1;
    int index = 0;
    if(s.length() == 0) return false;
    if(s[0] == '+' || s[0] == '-') index = 1;
    bool hasNumber = false;
    for(;index < s.length(); index++){
        char c = s[index];
        if(c == '.'){
            if(dot > 0) dot--;
            else return false;
        }else if(c - '0' < 0 || c - '0' > 9){
            return false;
        }else{
            hasNumber = true;
        }
    }
    if(dot == 1) return false;
    return hasNumber;
}

bool isInteger(string s){
    int index = 0;
    if(s.length() == 0) return false;
    if(s[0] == '+' || s[0] == '-') index = 1;
    bool hasNumber = false;
    for(;index < s.length(); index++){
        hasNumber = true;
        char c = s[index];
        if(c - '0' < 0 || c - '0' > 9){
            return false;
        }
    }
    return hasNumber;
}

bool isNumber(string s) {
    int index = s.find('e');
    if(index == std::string::npos) index = s.find('E');
    if(index != std::string::npos){
        string a = s.substr(0, index);
        string b = s.substr(index + 1);
        if((isDecimal(a) || isInteger(a)) && isInteger(b)){
            return true;
        }
    }
    return isDecimal(s) || isInteger(s);
}

void solve(){
    string s;
    cin >> s;
    cout << isNumber(s);
}

int main(void){
    solve();
    return 1;
}
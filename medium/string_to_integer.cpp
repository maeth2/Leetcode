#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool isDigit(char c){
    return c - '0' >= 0 && c - '0' <= 9;
}

int myAtoi(string s) {
    string number;
    int pon = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ' && number == ""){
            continue;
        }else if (s[i] == '+' && pon == 0 && number == "" && isDigit(s[i + 1])){
            pon = 1;
        }else if(s[i] == '-' && pon == 0 && number == "" && isDigit(s[i + 1])){
            pon = -1;
        }else if(isDigit(s[i])){
            number += s[i];
        }else{
            break;  
        }
    }

    while(number.length() != 0 && number[0] == '0'){
        number.erase(0, 1);
    }

    cout << number << "\n";
    pon = pon == 0 ? 1 : pon;
    string max_digits = "2147483647";
    if(max_digits.length() < number.length()){
        return pon == -1 ? INT32_MIN : INT32_MAX;
    }
    long ans = 0;
    long place = 1;
    for(int i = number.length() - 1; i >= 0; i--){
        ans += (number[i] - '0') * place;
        place *= 10;
        if(ans > INT32_MAX){
            return pon == -1 ? INT32_MIN : INT32_MAX;
        }
    }
    return pon * ans;
}

void solve(){
    string s;
    cin >> s;
    cout << myAtoi(s) << "\n";
}

int main(void){
    solve();
    return 1;
}
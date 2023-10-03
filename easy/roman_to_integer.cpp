#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;

int romanToInt(string s) {
    vector<int> roman(26);
    roman['I' - 'A'] = 1;
    roman['V' - 'A'] = 5;
    roman['X' - 'A'] = 10;
    roman['L' - 'A'] = 50;
    roman['C' - 'A'] = 100;
    roman['D' - 'A'] = 500;
    roman['M' - 'A'] = 1000;
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        int c = s[i] - 'A';
        if(i < s.length() - 1){
            if(roman[c] * 5 == roman[s[i + 1] - 'A']){
                ans += roman[c] * 4;
                i++;
                continue;
            }else if(roman[c] * 10 == roman[s[i + 1] - 'A']){
                ans += roman[c] * 9;
                i++;
                continue;
            }
        }
        ans += roman[c];
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    cout << romanToInt(s);
}

int main(void){
    solve();
    return 1;
}
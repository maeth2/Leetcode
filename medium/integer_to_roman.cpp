#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

string intToRoman(int num) {
    string ans = "";
    string place[4] = {
        "IV",
        "XL",
        "CD",
        "M"
    };
    string n = to_string(num);

    int p = n.length() - 1;
    for(int i = 0; i < n.length(); i++){
        int val = n[i] - '0';
        if(val == 5){
            ans += place[p][1];
        }else if(val < 5){
            if(val == 4){
                ans += place[p][0];
                ans += place[p][1];
            }else{
                for(int i = 0; i < val; i++){
                    ans += place[p][0];
                }
            }
        }else{
            if(val == 9){
                ans += place[p][0];
                ans += place[p + 1][0];
            }else{
                ans += place[p][1];
                for(int i = 0; i < val - 5; i++){
                    ans += place[p][0];
                }
            }
        }
        num /= 10;
        p--;
    }
    return ans;
}

void solve(){
    int num;
    cin >> num;
    cout << intToRoman(num);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int reverse(int x) {
    string max = "2147483647";
    string num = "";
    int co = 1;
    if(x < 0){
        co = -1;
        max = "2147483648";
    }
    while(x != 0){
        int i = x % 10;
        num += (x < 0 ? -i : i) + '0';
        x -= i;
        x /= 10;
    }
    
    bool bigger = false;
    if(num.size() == max.size()){
        for(int i = 0; i < num.size(); i++){
            if(max[i] - '0' == num[i] - '0'){
                continue;
            }else{
                bigger = max[i] < num[i];
                break;
            }
        }
    }
    if(bigger) return 0;

    int ans = 0;
    int place = 1;
    for(int i = num.length() - 1; i >= 0; i--){
        ans += (num[i] - '0') * place;
        if(i != 0) place *= 10;
    }
    return ans * co;
}

void solve(){
    int x;
    cin >> x;
    cout << reverse(x);
}

int main(void){
    solve();
    return 1;
}
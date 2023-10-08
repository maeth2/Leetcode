#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int r = 0;
    for(int i = n - 1; i >= 0; i--){
        int c = digits[i];
        if(i == n - 1) c += 1;
        c += r;
        if(c >= 10){
            r = 1;
            c -= 10;
        }else{
            r = 0;
        }
        digits[i] = c;
    }
    if(r == 1){
        digits.insert(digits.begin(), 1);
    }
    return digits;
}

void solve(){
    int n;
    cin >> n;
    vector<int> digits(n);
    for(int i = 0; i < n; i++){
        cin >> digits[i];
    }
    digits = plusOne(digits);
    for(int i : digits){
        cout << i << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
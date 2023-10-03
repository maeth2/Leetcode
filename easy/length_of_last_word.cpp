#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int lengthOfLastWord(string s) {
    int ans = 0;
    for(int i = s.length() - 1; i >= 0; i--){
        if(s[i] == ' '){
            if(ans != 0) return ans;
        }else{
            ans++;
        }
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    cout << lengthOfLastWord(s);
}

int main(void){
    solve();
    return 1;
}
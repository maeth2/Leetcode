#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c =='o' || c =='u';
}

int maxVowels(string s, int k) {
    int count = 0;
    for(int i = 0; i < k; i++){
        if(isVowel(s[i])) count++;
    }
    int ans = count;
    for(int i = k; i < s.length(); i++){
        if(isVowel(s[i - k])) count--;
        if(isVowel(s[i])) count++;
        ans = max(ans, count);
    }
    return ans;
}

void solve(){
    int k;
    string s;
    cin >> s >> k;
    cout << maxVowels(s, k);
}

int main(void){
    solve();
    return 1;
}
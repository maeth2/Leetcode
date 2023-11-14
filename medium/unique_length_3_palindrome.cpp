#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;
using ll = long long;

int countPalindromicSubsequence(string s) {
    int n = s.size();
    int ans = 0;
    set<char> letters;
    for(char c : s){
        letters.insert(c);
    }
    for(char c : letters){
        int first = -1;
        int last = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != c) continue;
            if(first == -1){
                first = i;
            }else{
                last = i;
            }
        }
        set<char> unique;
        for(int i = first + 1; i < last; i++){
            unique.insert(s[i]);
        }
        ans += unique.size();
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    cout << countPalindromicSubsequence(s);
}

int main(void){
    solve();
    return 1;
}
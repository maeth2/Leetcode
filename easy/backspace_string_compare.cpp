#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool backspaceCompare(string s, string t) {
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#'){
            if(i == 0){
                s.erase(i, 1);
                i--;
                continue;
            }
            s.erase(i - 1, 2);
            i -= 2;
        }
    }
    for(int i = 0; i < t.size(); i++){
        if(t[i] == '#'){
            if(i == 0){
                t.erase(i, 1);
                i--;
                continue;
            }
            t.erase(i - 1, 2);
            i -= 2;
        }
    }
    return s == t;
}

bool backspaceCompare1(string s, string t) {
    int j = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#'){
            if(j > 0) j--;
        }else{
            s[j] = s[i];
            j++;
        }
    }
    int k = 0;
    for(int i = 0; i < t.size(); i++){
        if(t[i] == '#'){
            if(k > 0) k--;
        }else{
            t[k] = t[i];
            k++;
        }
    }
    return s.substr(0, j) == t.substr(0, k);
}

void solve(){
    string s, t;
    cin >> s >> t;
    cout << backspaceCompare(s, t);
}

int main(void){
    solve();
    return 1;
}
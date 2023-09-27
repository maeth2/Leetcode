#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;
using ll = long long;

int longestValidParentheses(string s) {
    stack<int> stk;
    int ans = 0;
    int index = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            stk.push(i);
        }else{
            if(stk.empty()) {
                index = i + 1;
            }else{
                stk.pop();
                if (stk.empty()) {
                    ans = max(ans, i - index + 1);
                } else {
                    ans = max(ans, i - stk.top());
                }
            }
        }
    }
    return ans;
}

int longestValidParentheses1(string s) {
    string t = s;
    bool changes = true;
    while(changes){
        int prev = -1;
        changes = false;
        for(int i = 0; i < s.length(); i++){
            if(t[i] == ' ') continue;
            if(prev == -1){
                prev = i;
                continue;
            }
            if(s[prev] == '(' && s[i] == ')'){
                t[prev] = ' ';
                t[i] = ' ';
                changes = true;
            }
            prev = i;
        }
    }
    int ans = 0;
    int count = 0;
    for(int i = 0; i < t.length(); i++){
        if(t[i] == ' ') count++;
        else count = 0;
        ans = max(ans, count);
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    cout << longestValidParentheses(s);
}

int main(void){
    solve();
    return 1;
}
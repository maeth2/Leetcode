#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

string removeDuplicateLetters(string s) {
    vector<int> pos(26);
    vector<bool> seen(26);
    for(int i = 0; i < s.length(); i++){
        pos[s[i] - 'a'] = i;
    }
    string ans = "";
    ans += s[0];
    seen[s[0] - 'a'] = true;
    for(int i = 1; i < s.length(); i++){
        char c = s[i];
        if(seen[c - 'a']) continue;
        while(ans.length() > 0 && c < ans[ans.length() - 1] && i < pos[ans[ans.length() - 1] - 'a']){
            seen[ans[ans.length() - 1] - 'a'] = false;
            ans.erase(ans.length() - 1, 1);
        }
        ans.push_back(s[i]);
        seen[s[i] - 'a'] = true;
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    cout << removeDuplicateLetters(s);
}

int main(void){
    solve();
    return 1;
}
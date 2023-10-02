#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

string justify(vector<string> s, int width, int maxWidth){
    string ans = "";
    int n = s.size();
    int gaps = n - 1 > 0 ? n - 1 : 1;
    int total = maxWidth - width;
    int spaces = total / gaps;
    int extra = total % gaps;
    for(int i = 0; i < n; i++){
        ans += s[i];
        if(total > 0){
            for(int i = 0; i < spaces; i++){
                ans += ' ';
                total--;
            }
        }
        if(extra){
            ans += ' ';
            extra--;
            total--;
        }
    }
    return ans;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int width = 0;
    vector<string> ans;
    vector<string> line;
    for(int i = 0; i < words.size(); i++){
        string s = words[i];
        if(width + s.length() > maxWidth){
            ans.push_back(justify(line, width - line.size(), maxWidth));
            line.clear();
            width = 0;
        }
        line.push_back(s);
        width += s.length() + 1;
    }
    string s = "";
    for(int i = 0; i < line.size(); i++){
        s += line[i];
        if(i < line.size() - 1) s += ' ';
    }
    int remain = maxWidth - s.length();
    for(int i = 0; i < remain; i++){
        s += ' ';
    }
    ans.push_back(s);
    return ans;
}

void solve(){
    int n, maxWidth;
    cin >> n >> maxWidth;
    vector<string> words(n);
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }
    vector<string> ans = fullJustify(words, maxWidth);
    for(string s : ans){
        cout << s << "\n";
    }
}

int main(void){
    solve();
    return 1;
}
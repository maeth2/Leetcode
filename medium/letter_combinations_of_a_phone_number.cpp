#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void recurse(int i, string current, string &digits, vector<string> &letters, vector<string> &ans){
    if(i == digits.length()){
        ans.push_back(current);
        return;
    }
    int number = digits[i] - '1';
    for(char c : letters[number]){
        recurse(i + 1, current + c, digits, letters, ans);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    vector<string> letters = {
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    if(digits.length() == 0) return ans;
    recurse(0, "", digits, letters, ans);
    return ans;
}

void solve(){
    string digits;
    cin >> digits;
    vector<string> ans = letterCombinations(digits);
    for(string s : ans){
        cout << s << '\n';
    }
}

int main(void){
    solve();
    return 1;
}
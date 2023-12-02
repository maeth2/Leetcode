#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool checkWord(string i, vector<int> count){
    for(char c : i){
        count[c - 'a']--;
        if(count[c - 'a'] < 0) return false;
    }
    return true;
}

int countCharacters(vector<string>& words, string chars) {
    int ans = 0;
    vector<int> count(26);
    for(char c : chars){
        count[c - 'a']++;
    }
    for(string i : words){
        if(checkWord(i, count)){
            ans += i.size();
        }
    }
    return ans;
}

void solve(){
    int n;
    string chars;
    cin >> n >> chars;
    vector<string> words(n);
    for(int i = 0; i < n; i++) cin >> words[i];
    cout << countCharacters(words, chars);
}

int main(void){
    solve();
    return 1;
}
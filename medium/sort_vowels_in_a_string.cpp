#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

string sortVowels(string s) {
    string ans;
    vector<int> vowels;
    for(char c : s){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            ans += ' ';
            vowels.push_back(c);
        }else{
            ans += c;
        }
    }
    sort(vowels.begin(), vowels.end());
    int index = 0;
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == ' '){
            ans[i] = vowels[index++];
        }
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    cout << sortVowels(s);
}

int main(void){
    solve();
    return 1;
}
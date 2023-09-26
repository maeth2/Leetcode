#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
using ll = long long;

vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> w;
    for(string i : words){  
        w[i]++;
    }
    vector<int> ans;
    int size = words[0].size();
    int total = size * words.size();
    int length = s.length();;
    for(int i = 0; i <= length - total; i++){
        int count = 0;
        unordered_map<string, int> w1;
        for(int j = 0; j < total; j += size){
            string sub = s.substr(i + j, size);
            w1[sub]++;
            if(w1[sub] > w[sub]) break;
            count++;
        }
        if(count == words.size()) ans.push_back(i);
    }
    return ans;
}

void solve(){
    string s;
    int n;
    cin >> s >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }
    vector<int> ans = findSubstring(s, words);
    for(int i : ans){
        cout << i << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
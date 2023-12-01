#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string a = "";
    string b = "";
    for(string i : word1){
        a += i;
    }
    for(string i : word2){
        b += i;
    }
    return a == b;
}

void solve(){
    int n, m;
    vector<string> word1(n);
    vector<string> word2(m);
    for(int i = 0; i < n; i++) cin >> word1[i];
    for(int i = 0; i < m; i++) cin >> word2[i];
    cout << arrayStringsAreEqual(word1, word2);
}

int main(void){
    solve();
    return 1;
}
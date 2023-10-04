#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int recurse(int word, int currentScore, vector<string>& words, vector<int> count, vector<int>& score){
    if(word == words.size()) return currentScore;
    bool use = true;
    int ans = recurse(word + 1, currentScore, words, count, score);
    for(char i : words[word]){
        count[i - 'a']--;
        if(count[i - 'a'] < 0){
            use = false;
            break;
        }
        currentScore += score[i - 'a'];
    }
    if(use){
        ans = max(ans, recurse(word + 1, currentScore, words, count, score));
    }
    return ans;
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    vector<int> count(26);
    for(char i : letters){
        count[i - 'a']++;
    }
    return recurse(0, 0, words, count, score);
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> words(n);
    vector<char> letters(m);
    vector<int> score(26);
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }
    for(int i = 0; i < m; i++){
        cin >> letters[i];
    }
    for(int i = 0; i < 26; i++){
        cin >> score[i];
    }
    cout << maxScoreWords(words, letters, score);
}

int main(void){
    solve();
    return 1;
}
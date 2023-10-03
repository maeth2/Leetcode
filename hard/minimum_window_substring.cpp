#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;

int charToIndex(char c){
    if(c - 'a' < 0){
        return 26 + c - 'A';
    }
    return c - 'a';
}

/*
    Uses BitMask to determine if substring reaches requirement
*/
string minWindow(string s, string t) {
    if(s.length() < t.length()) return "";
    long mask = 0;
    vector<int> count(52);
    for(int i = 0; i < t.length(); i++){
        int index = charToIndex(t[i]);
        mask = mask | (1LL << index);
        count[index]++;
    }
    long currentMask = 0;
    int mi = INT_MAX;
    int i, j = 0;    
    vector<int> currentCount(52);
    int left = 0;
    int right = 0;
    while(left < s.length()){
        if((currentMask & mask) != mask && right < s.length()){
            int index = charToIndex(s[right]);
            currentCount[index]++;
            if(currentCount[index] >= count[index]){
                currentMask = currentMask | (1LL << index);
            }
            right++;
        }
        if((currentMask & mask) == mask || right == s.length()){
            int index = charToIndex(s[left]);
            int length = right - left;
            if(length < mi && (currentMask & mask) == mask){
                mi = length;
                i = left;
                j = right;
            }
            currentCount[index]--;
            if(currentCount[index] < count[index] && (currentMask & (1LL << index))){
                currentMask = currentMask ^ (1LL << index);
            }
            left++;
        }
    }
    if(mi == INT_MAX) return "";
    return s.substr(i, j - i);
}

/*
    Uses HashMap to determine if substring reaches requirement
*/
string minWindow1(string s, string t) {
    if(s.length() < t.length()) return "";
    map<char, int> count;
    for(int i = 0; i < t.length(); i++){
        count[t[i]]++;
    }
    int mi = INT_MAX;
    int i, j = 0;
    int left = 0;
    int right = 0;
    int total = count.size();
    while(left < s.length()){
        if(total != 0 && right < s.length()){
            if(count.find(s[right]) != count.end()){
                count[s[right]]--;
                if(count[s[right]] == 0){
                    total--;
                }
            }
            right++;
        }
        if(total == 0 || right == s.length()){
            int length = right - left;
            if(total == 0 && length < mi){
                i = left;
                j = right;
                mi = length;
            }
            if(count.find(s[left]) != count.end()){
                count[s[left]]++;
                if(count[s[left]] > 0){
                    total++;
                }
            }
            left++;
        }
    }
    if(mi == INT_MAX) return "";
    return s.substr(i, j - i);
}

void solve(){
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << '\n';
}

int main(void){
    solve();
    return 1;
}
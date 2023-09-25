#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int lengthOfLongestSubstring(string s) {
    if(s.length() == 0) return 0;
    int j = 1;
    int i = 0;
    int ans = 1;
    while(j < s.length()){
        if(j - i == 0){
           j++;
           continue;
        }
        if(s.substr(i, j - i).find(s[j]) != std::string::npos){
            i++;
            continue;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
}

int main(void){
    solve();
    return 1;
}
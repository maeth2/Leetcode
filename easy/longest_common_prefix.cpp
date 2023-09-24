#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
/*
    Note: I did not read the question properly and mistook Longest Common Prefix with Longest Common Sub-sequence hence the recursize function below.
*/

// string recurse(vector<string> strs, vector<int> index, string prefix){
//     for(int i = 0; i < strs.size(); i++){
//         if(index[i] == strs[i].size()) return prefix;
//     }

//     bool same = true;
//     char c = strs[0][index[0]];
//     for(int i = 1; i < strs.size(); i++){
//         if(strs[i][index[i]] != c){
//             same = false;
//             break;
//         }
//     }
//     string ans = prefix;
//     if(same){
//         for(int i = 0; i < index.size(); i++){
//             index[i]++;
//         }
//         prefix += c;
//         ans = recurse(strs, index, prefix);
//     }else{
//         for(int i = 0; i < strs.size(); i++){
//             index[i]++;
//             string s = recurse(strs, index, "");
//             index[i]--;
//             if(ans.length() < s.length()){
//                 ans = s;
//             }
//         }
//     }
//     return ans;
// }

string longestCommonPrefix(vector<string>& strs) {
    vector<int> index(strs.size());
    if(strs.size() == 0) return "";
    string prefix = strs[0];
    for(int i = 1; i < strs.size(); i++){
        while(strs[i].find(prefix) != 0){
            prefix.erase(prefix.begin() + prefix.size() - 1);
            if(prefix.size() == 0){
                return "";
            }
        }
    }
    return prefix;
}

void solve(){
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << longestCommonPrefix(a);
}

int main(void){
    solve();
    return 1;
}
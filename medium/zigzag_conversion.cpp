#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

string convert(string s, int numRows) {
    int gap = max(1, numRows + numRows - 2);
    int col = ceil(s.length() / (numRows * 1.0));
    string ans = "";
    for(int i = 0; i < numRows; i++){
        if(i == 0 || i == numRows - 1){
            for(int j = 0; j < col; j++){
                int index = i + j * gap;
                if(index < s.length()) ans += s[index];
            }
        }else{
            for(int j = 0; j < col; j++){
                int diag = j * gap + gap - i;
                int index = i + j * gap;
                if(index < s.length()) ans += s[index];
                if(diag < s.length()) ans += s[diag];
            }
        }
    }
    return ans;
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    cout << convert(s, n);
}

int main(void){
    solve();
    return 1;
}
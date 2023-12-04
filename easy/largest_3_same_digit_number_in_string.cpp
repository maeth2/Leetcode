#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

string largestGoodInteger(string num) {
    string ans = "";
    string curr = "";
    for(char c : num){
        if(curr == "" || c == curr[0]){
            if(curr.length() < 3) curr += c;
        }else{
            if(curr.length() == 3 && (ans == "" || ans[0] - '0' < curr[0] - '0')){
                ans = curr;
            }
            curr = c;
        }
    }
    if(curr.length() == 3 && (ans == "" || ans[0] - '0' < curr[0] - '0')){
        ans = curr;
    }
    return ans;
}

void solve(){
    string num;
    cin >> num;
    cout << largestGoodInteger(num);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<string> buildArray(vector<int>& target, int n) {
    int index = 0;
    vector<string> ans;
    for(int i = 1; i <= n; i++){
        ans.push_back("Push");
        if(target[index] == i){
            index++;
        }else{
            ans.push_back("Pop");
        }
    }
    return ans;
}

void solve(){
    int m, n;
    cin >> m >> n;
    vector<int> target(m);
    for(int i = 0; i < m; i++) cin >> target[i];
    vector<string> ans = buildArray(target, n);
    for(string i : ans) cout << i << ' ';
}

int main(void){
    solve();
    return 1;
}
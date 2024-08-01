#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int countSeniors(vector<string>& details) {
    int ans = 0;
    for(string i : details){
        int first = i[11] - '0';
        int second = i[12] - '0';
        if(first > 6){
            ans++;
        }else if(first == 6 && second > 0){
            ans++;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<string> details(n);
    for(int i = 0; i < n; i++){
        cin >> details[i];
    }
    cout << countSeniors(details);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    vector<int> prefix(n);
    vector<int> count(n);
    int sum = 0;
    int ac = 0;
    for(int i = 0; i < n; i++){
        sum += customers[i];
        ac += grumpy[i] == 1 ? 0 : customers[i];
        count[i] = ac;
        prefix[i] = sum;
    }
    int mx = -1;
    for(int i = 0; i <= n - minutes; i++){
        int a = 0, b = 0, c = 0;
        if(i - 1 >= 0){
            a = count[i - 1];
        }
        if(i - 1 >= 0){
            b = prefix[i + minutes - 1] - prefix[i - 1];
        }else{
            b = prefix[i + minutes - 1];
        }
        if(i + minutes < n){
            c = count[n - 1] - count[i + minutes - 1];
        }
        mx = max(mx, a + b + c);
    }
    return mx;
}

void solve(){
    int n;
    cin >> n;
    vector<int> customers(n);
    vector<int> grumpy(n);
    for(int i = 0; i < n; i++){
        cin >> customers[i];
    }
    for(int i = 0; i < n; i++){
        cin >> grumpy[i];
    }
    int minutes;
    cin >> minutes;
    cout << maxSatisfied(customers, grumpy, minutes);
}

int main(void){
    solve();
    return 1;
}
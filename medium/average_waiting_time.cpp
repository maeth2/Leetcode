#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

double averageWaitingTime(vector<vector<int>>& customers) {
    double n = customers.size();
    int time = 0;
    double ans = 0;
    for(vector<int> i : customers){
        time = max(i[0], time) + i[1];
        ans += time - i[0];
    }
    return ans / n;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> customers(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> customers[i][0] >> customers[i][1];
    }
    cout << averageWaitingTime(customers);
}

int main(void){
    solve();
    return 1;
}
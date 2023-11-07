#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = dist.size();
    vector<int> min(n);
    for(int i = 0; i < n; i++){
        min[i] = ceil((1.0 * dist[i]) / speed[i]);
    }
    sort(min.begin(), min.end());
    for(int i = 0; i < n; i++){
        if(min[i] <= i) return i;
    }
    return n;
}

void solve(){
    int n;
    cin >> n;
    vector<int> dist(n);
    vector<int> speed(n);
    for(int i = 0; i < n; i++) cin >> dist[i];
    for(int i = 0; i < n; i++) cin >> speed[i];
    cout << eliminateMaximum(dist, speed);
}

int main(void){
    solve();
    return 1;
}
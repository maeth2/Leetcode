#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int n = garbage.size();
    vector<int> typeDist(3);
    int count = 0;
    int dist = 0;
    for(int i = 0; i < n; i++){
        for(char c : garbage[i]){
            if(c == 'M'){
                typeDist[0] = dist;
            }else if(c == 'P'){
                typeDist[1] = dist;
            }else if(c == 'G'){
                typeDist[2] = dist;
            }
            count++;
        }
        if(i < n - 1) dist += travel[i];
    }

    int totalDist = 0;
    for(int i = 0; i < 3; i++){
        totalDist += typeDist[i];
    }
    return totalDist + count;
}

void solve(){
    int n;
    cin >> n;
    vector<string> garbage(n);
    vector<int> travel(n - 1);
    for(int i = 0; i < n; i++) cin >> garbage[i];
    for(int i = 0; i < n - 1; i++) cin >> travel[i];
    cout << garbageCollection(garbage, travel);
}

int main(void){
    solve();
    return 1;
}
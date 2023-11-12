#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;
using ll = long long;


int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    int n = routes.size();
    map<int, vector<int>> stops;
    if(source == target) return 0;
    for(int i = 0; i < n; i++){
        for(int j : routes[i]){
            stops[j].push_back(i);
        }
    }
    queue<pair<int, int>> pq;
    vector<int> searched(n);
    for(int i : stops[source]) pq.emplace(1, i);
    while(!pq.empty()){
        int t = pq.front().first;
        int i = pq.front().second;
        pq.pop();
        if(searched[i]) continue;
        searched[i] = true;
        for(int j : routes[i]){
            if(j == target){
                return t;
            }else{
                for(int k : stops[j]){
                    if(!searched[k]) pq.emplace(t + 1, k);
                }
            }
        }
    }
    return -1;
}

void solve(){
    int n, source, target;
    cin >> n >> source >> target;
    vector<vector<int>> routes(n);
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int k;
            cin >> k;
            routes[i].push_back(k);
        }
    }
    cout << numBusesToDestination(routes, source, target);
}

int main(void){
    solve();
    return 1;
}
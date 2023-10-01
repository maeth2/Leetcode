#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

/*
    NOTE: We can just use a normal queue in this situation because all the weights are uniform. The count will automatically be placed from least to greatest in
    the queue.

    NOTE: This means that we will always save the smallest value for (index, mask).
*/
int shortestPathLength(vector<vector<int>>& graph) {
    queue<tuple<int, int, int>> pq;
    int filled = pow(2, graph.size()) - 1;
    vector<vector<bool>> searched(graph.size(), vector<bool>(filled));
    for(int i = 0; i < graph.size(); i++){
        pq.emplace(0, 0, i);
    }
    while(!pq.empty()){
        int count = get<0>(pq.front());
        int mask = get<1>(pq.front());
        int index = get<2>(pq.front());
        pq.pop();
        mask = mask | (1 << index);
        if(mask == filled) return count;
        if(searched[index][mask]) continue;
        searched[index][mask] = true;
        for(int i : graph[index]){
            pq.emplace(count + 1, mask, i);
        }
    }
    return -1;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n; i++){
        int n1;
        cin >> n1;
        for(int j = 0; j < n1; j++){
            int a;
            cin >> a;
            graph[i].push_back(a);
        }
    }
    cout << shortestPathLength(graph);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

class Graph {
public:
    vector<vector<pair<int, int>>> graph;
    Graph(int n, vector<vector<int>>& edges) {
        graph = vector<vector<pair<int, int>>>(n);
        for(vector<int> i : edges){
            graph[i[0]].emplace_back(i[1], i[2]);
        }

    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> searched(graph.size());
        pq.emplace(0, node1);
        while(!pq.empty()){
            int c = pq.top().first;
            int i = pq.top().second;
            if(i == node2) return c;
            pq.pop();
            searched[i] = true;
            for(pair<int, int> j : graph[i]){
                if(!searched[j.first]) pq.emplace(c + j.second, j.first);
            }
        }
        return -1;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for(int i = 0; i < m; i++) cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    Graph *g = new Graph(n, edges);
    cout << g->shortestPath(3, 2) << "\n";
    cout << g->shortestPath(0, 3) << "\n";
    g->addEdge({1, 3, 4});
    cout << g->shortestPath(0, 3) << "\n";
}

int main(void){
    solve();
    return 1;
}
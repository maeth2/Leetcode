#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<int> topSort(int k, vector<vector<int>> con){
    vector<vector<int>> adj(k + 1);
    vector<int> searched(k + 1);
    vector<int> sorted;
    for(vector<int> i : con){
        adj[i[0]].push_back(i[1]);
    }
    bool hasCycle = false;
    for(int i = 1; i <= k; i++){
        if(searched[i] == 0){
            dfs(i, adj, searched, sorted, hasCycle);
            if(hasCycle){
                return {};
            }
        }
    }
    reverse(sorted.begin(), sorted.end());
    return sorted;
}

void dfs(int i, vector<vector<int>>& adj, vector<int>& searched, vector<int> &sorted, bool &hasCycle){
    searched[i] = 1;
    for(int j : adj[i]){
        if(searched[j] == 0){
            dfs(j, adj, searched, sorted, hasCycle);
            if(hasCycle){
                return;
            }
        }else if(searched[j] == 1){
            hasCycle = true;
            return;
        }
    }
    searched[i] = 2;
    sorted.push_back(i);
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> sortedRows = topSort(k, rowConditions);
    vector<int> sortedCols = topSort(k, colConditions);
    
    if(sortedRows.empty() || sortedCols.empty()){
        return{};
    }

    vector<vector<int>> ans(k, vector<int>(k, 0));
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(sortedRows[i] == sortedCols[j]){
                ans[i][j] = sortedRows[i];
            }
        }
    }
    return ans;
}

void solve(){   
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<int>> rowConditions(n, vector<int>(2));
    vector<vector<int>> colConditions(m, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> rowConditions[i][0] >> rowConditions[i][1];
    }
    for(int i = 0; i < m; i++){
        cin >> colConditions[i][0] >> colConditions[i][1];
    }
    vector<vector<int>> ans = buildMatrix(k, rowConditions, colConditions);
    for(vector<int> i : ans){
        for(int j : i){
            cout << j << ' ';
        }
        cout << "\n";
    }
}

int main(void){
    solve();
    return 1;
}
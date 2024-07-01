#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

int find(int i, vector<int>& parent){
    if(i == parent[i]) return i;
    parent[i] = find(parent[i], parent);
    return parent[i];
}

bool check(int a, int b, vector<int>& parent){
    int au = find(a, parent);
    int bu = find(b, parent);
    if(au == bu){
        return 1;
    }
    parent[au] = bu;
    return 0;
}

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    int ans = 0;
    vector<int> parentA(n + 1);
    vector<int> parentB(n + 1);
    for(int i = 1; i <= n; i++){
        parentA[i] = i;
        parentB[i] = i;
    }
    for(vector<int> i : edges){
        if(i[0] == 3){
            int a = i[1];
            int b = i[2];
            if(check(a, b, parentA) || check(a, b, parentB)){
                ans++;
            }else{
                check(a, b, parentA);
                check(a, b, parentB);
            }
        }
    }
    cout << ans << "\n";
    for(vector<int> i : edges){
        int a = i[1];
        int b = i[2];
        if(i[0] == 1){
            if(check(a, b, parentA)){
                ans++;
            }
        }else if(i[0] == 2){
            if(check(a, b, parentB)){
                ans++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(!check(1, i, parentA) || !check(1, i, parentB)){
            return -1;
        }
    }
    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> edges(k, vector<int>(3));
    for(int i = 0; i < k; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    cout << maxNumEdgesToRemove(n, edges);
}

int main(void){
    solve();
    return 1;
}
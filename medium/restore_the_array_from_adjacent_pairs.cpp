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

vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    map<int, vector<int>> count;
    for(vector<int> i : adjacentPairs){
        count[i[0]].push_back(i[1]);
        count[i[1]].push_back(i[0]);
    }
    queue<int> pq;
    for(auto &i : count){
        if(i.second.size() == 1){
            pq.push(i.first);
            break;
        }
    }
    vector<int> ans;
    vector<int> searched(2e5);
    while(!pq.empty()){
        int i = pq.front();
        searched[i + 1e5] = true;
        pq.pop();
        ans.push_back(i);
        for(int j : count[i]){
            if(!searched[j + 1e5]) pq.push(j);
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adjacentPairs(n, vector<int>(2));
    for(int i = 0; i < n; i++) cin >> adjacentPairs[i][0] >> adjacentPairs[i][1];
    vector<int> ans = restoreArray(adjacentPairs);
    for(int i : ans) cout << i << ' ';
}

int main(void){
    solve();
    return 1;
}
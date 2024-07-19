#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> mr(m);
    vector<int> mc(n);
    for(int i = 0; i < m; i++){
        mr[i] = -1;
    }
    for(int i = 0; i < n; i++){
        mc[i] = INT32_MAX;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mc[i] = min(mc[i], matrix[i][j]);
            mr[j] = max(mr[j], matrix[i][j]);
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mc[i] == mr[j]){
                ans.push_back(mc[i]);
            }
        }
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    vector<int> ans = luckyNumbers(matrix);
    for(int i : ans){
        cout << i << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
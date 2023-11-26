#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;
using ll = long long;

int largestSubmatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> count(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0){
                count[i][j] = matrix[i][j];
            }else{
                if(matrix[i][j]) count[i][j] = count[i - 1][j] + 1;
                else count[i][j] = 0;
            }
        }
    }

    int ans = -1;
    for(vector<int> i : count){
        sort(i.begin(), i.end(), greater<int>());
        for(int j = 0; j < m; j++){
            ans = max(ans, (j + 1) * i[j]);
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
    cout << largestSubmatrix(matrix);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int ans = 0;
    int x = points[0][0];
    int y = points[0][1];
    for(int i = 1; i < points.size(); i++){
        int dx = abs(points[i][0] - x);
        int dy = abs(points[i][1] - y);
        ans += min(dx, dy) + (max(dx, dy) - min(dx, dy));
        x = points[i][0];
        y = points[i][1];
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for(int i = 0; i < n; i++) cin >> points[i][0] >> points[i][1];
    cout << minTimeToVisitAllPoints(points);
}

int main(void){
    solve();
    return 1;
}
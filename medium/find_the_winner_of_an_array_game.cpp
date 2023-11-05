#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

int getWinner(vector<int>& arr, int k) {
    int count = 0;
    int i = 0;
    int j = 1;
    queue<int> pq;
    int mx = INT_MIN;
    for(int i : arr){
        pq.push(i);
        mx = max(mx, i);
    }
    if(k >= arr.size()) return mx;
    int curr = pq.front();
    pq.pop();

    while(count < k){
        int opp = pq.front();
        pq.pop();
        if(curr >= opp){
            pq.push(opp);
            count++;
        }else{
            count = 1;
            curr = opp;
            pq.push(curr);
        }
    }
    return curr;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << getWinner(arr, k);
}

int main(void){
    solve();
    return 1;
}
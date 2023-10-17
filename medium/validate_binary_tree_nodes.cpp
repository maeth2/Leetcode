#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    vector<bool> searched(n);
    int root = -1;
    for(int i = 0; i < n; i++){
        int lc = leftChild[i];
        int rc = rightChild[i];
        if(lc != -1) searched[lc] = true;
        if(rc != -1) searched[rc] = true;
    }
    for(int i = 0; i < n; i++){
        if(!searched[i]){
            root = i;
            break;
        }
    }
    if(root == -1) return false;
    searched = vector<bool>(n, 0);
    queue<int> pq;
    pq.push(root);
    int total = n;
    while(!pq.empty()){
        int i = pq.front();
        searched[i] = true;
        total--;
        pq.pop();
        int lc = leftChild[i];
        int rc = rightChild[i];
        if(lc != -1){
            if(searched[lc]) return false;
            pq.push(lc);
        }
        if(rc != -1){
            if(searched[rc]) return false;
            pq.push(rc);
        }
    }
    return total == 0;
}

void solve(){
    int n;
    cin >> n;
    vector<int> leftChild(n);
    vector<int> rightChild(n);
    for(int i = 0; i < n; i++) cin >> leftChild[i];
    for(int i = 0; i < n; i++) cin >> rightChild[i];
    cout << validateBinaryTreeNodes(n, leftChild, rightChild);
}

int main(void){
    solve();
    return 1;
}
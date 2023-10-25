#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

/*
    NOTE: For each layer in the tree, check if (n, k) lies in the left or right side of the current node. Keep recursing until we are left with one node.
*/

int recurse(int n, int k, int val){
    if(n == 1) return val;
    int l = pow(2, n - 1);
    if(k > l / 2){
        return recurse(n - 1, k - (l / 2), val == 0 ? 1 : 0);
    }else{
        return recurse(n - 1, k, val == 0 ? 0 : 1);
    }
}

int kthGrammar(int n, int k) {
    return recurse(n, k, 0);
}

void solve(){
    int n, k;
    cin >> n >> k;
    cout << kthGrammar(n, k);
}

int main(void){
    solve();
    return 1;
}
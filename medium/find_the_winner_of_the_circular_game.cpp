#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int findTheWinner(int n, int k) {
    vector<int> li(n);
    for(int i = 0; i < n; i++){
        li[i] = i + 1;
    }
    int index = 0;
    while(li.size() > 1){
        int size = li.size();
        if(index >= size){
            index = 0;
        }
        int skip = (k - 1) % size;
        int remove = (index + skip) % size;
        li.erase(li.begin() + remove);
        index = remove;
    }
    return li[0];
}

void solve(){
    int n, k;
    cin >> n >> k;
    cout << findTheWinner(n, k);
}

int main(void){
    solve();
    return 1;
}
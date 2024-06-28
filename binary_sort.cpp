#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int binary_search(vector<int> arr, int i){
    int l = 0;
    int r = arr.size() - 1;
    while(l <= r){
        cout << l << ' ' << r << "\n";
        int m = (l + r) / 2;
        if(i >= arr[m]){
            l = m;
        }else{
            r = m - 1;
        }
    }  
    return l;
}

vector<int> binary_sort(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        int loc = binary_search(ans, arr[i]);
        ans.insert(ans.begin() + loc, arr[i]);
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> sorted = binary_sort(arr);
    for(int i : sorted){
        cout << i << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
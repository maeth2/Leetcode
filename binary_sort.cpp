#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int binary_search(vector<int> arr, int i, int low, int high){
    int l = low;
    int r = high;
    while(l <= r){
        int m = (l + r) / 2;
        if(i >= arr[m]){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }  
    return l;
}

vector<int> binary_sort(vector<int> &arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int loc = binary_search(arr, arr[i], 0, i - 1);
        int v = arr[i];
        for(int j = i - 1; j >= loc; j--){
            arr[j + 1] = arr[j];
        }
        arr[loc] = v;
    }
    return arr;
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
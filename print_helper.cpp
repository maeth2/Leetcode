#include <iostream>
#include <vector>

using namespace std;

template <typename T> 
void print(vector<T> a){
    for(T j : a){
        cout << j << ' ';
    }
    cout << "\n";
}

template <typename T> 
void print_sub(vector<T> a, int l, int r){
    for(int i = l; i <= r; i++){
        cout << a[i] << ' ';
    }
    cout << "\n";
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;
using ll = long long;

class MyHashMap {
public:
    vector<int> hashMap;
    MyHashMap() {
        vector<int> temp(1000001, -1);
        hashMap = temp;
    }
    
    void put(int key, int value) {
        hashMap[key] = value;
    }
    
    int get(int key) {
        return hashMap[key];
    }
    
    void remove(int key) {
        hashMap[key] = -1;
    }
};

void solve(){
}

int main(void){
    solve();
    return 1;
}
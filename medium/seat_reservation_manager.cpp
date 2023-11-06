#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> tables;
    
    SeatManager(int n) {
        for(int i = 1; i <= n; i++){
            tables.emplace(i);
        }
    }
    
    int reserve() {
        int i = tables.top();
        tables.pop();
        return i;
    }
    
    void unreserve(int seatNumber) {
        tables.emplace(seatNumber);
    }
};

void solve(){
    SeatManager* i = new SeatManager(5);
    i->reserve();
    i->reserve();
    i->unreserve(2);
    i->reserve();
    i->reserve();
    i->reserve();
    i->reserve();
    i->unreserve(5);
}

int main(void){
    solve();
    return 1;
}
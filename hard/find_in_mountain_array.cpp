#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

class MountainArray {
   public:
        vector<int> array;
        int get(int index){
            if(index < 0 || index >= array.size()) cout << "ERROR\n";
            return array[index];
        }
        int length(){
            return array.size();
        }
};

int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length();
    /*
        GETTING THE INDEX FOR THE PEAK
    */
    int peak = -1;
    int l = 0;
    int r = n - 1;
    int middle = 0;
    while(l <= r){
        middle = (l + r) / 2;
        int m = mountainArr.get(middle);
        int ml = middle == 0 ? -1 : mountainArr.get(middle - 1);
        int mr = middle == n - 1 ? -1 : mountainArr.get(middle + 1);
        if((middle == 0 && m > mr) || (middle == n - 1 && m > ml) || (m > ml && m > mr)){
            peak = middle;
            break;
        }else if(ml > m){
            r = middle - 1;
        }else{
            l = middle + 1;
        }
    }
    /*
        ASCENDING PORTION
    */
    l = 0;
    r = peak;
    while(l <= r){
        middle = (l + r) / 2;
        int m = mountainArr.get(middle);
        if(m == target){
            return middle;
        }else if(m < target){
            l = middle + 1;
        }else{
            r = middle - 1;
        }
    }
    /*
        DESCENDING PORTION
    */
    l = peak;
    r = n - 1;
    while(l <= r){
        middle = (l + r) / 2;
        int m = mountainArr.get(middle);
        if(m == target){
            return middle;
        }else if(m < target){
            r = middle - 1;
        }else{
            l = middle + 1;
        }
    }
    return -1;
}

void solve(){
    int n, target;
    cin >> n >> target;
    MountainArray mountainArr = MountainArray();
    mountainArr.array = vector<int>(n);
    for(int i = 0; i < n; i++){
        cin >> mountainArr.array[i];
    }
    cout << findInMountainArray(target, mountainArr);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;
using ll = long long;

int search_upper(int target, vector<int>& nums){
    int left = 0;
    int right = nums.size() - 1;
    int ans = -1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(nums[middle] == target){
            left = middle + 1;
        }else if(nums[middle] < target){
            left = middle + 1;
        }else if(nums[middle] > target){
            ans = middle;
            right = middle - 1;
        }
    }
    return ans == -1 ? left : ans;
}

int search_lower(int target, vector<int>& nums){
    int left = 0;
    int right = nums.size() - 1;
    int ans = -1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(nums[middle] == target){
            right = middle - 1;
        }else if(nums[middle] < target){
            left = middle + 1;
            ans = middle;
        }else if(nums[middle] > target){
            right = middle - 1;
        }
    }
    return ans == -1 ? right : ans;
}

vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    vector<int> ans;
    vector<int> start;
    vector<int> end;
    for(vector<int> i : flowers){
        start.push_back(i[0]);
        end.push_back(i[1]);
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    for(int i : start) cout << i << ' ';
    cout << "\n";
    for(int i : end) cout << i << ' ';
    cout << "\n";
    for(int i : people){
        int s = search_upper(i, start);
        int e = search_lower(i, end) + 1;
        ans.push_back(s - e);
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> flowers(n, vector<int>(2));
    vector<int> people(m);
    for(int i = 0; i < n; i++){
        cin >> flowers[i][0] >> flowers[i][1];
    }
    for(int i = 0; i < m; i++){
        cin >> people[i];
    }
    people = fullBloomFlowers(flowers, people);
    for(int i : people){
        cout << i << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
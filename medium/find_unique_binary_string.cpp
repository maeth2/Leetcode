#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

string toBinary(int i, int n){
    string ans;
    for(int j = 0; j < n; j++) ans += '0';
    n--;
    while(i > 0){
        ans[n--] = (i % 2) + '0';
        i -= i % 2;
        i /= 2;
    }
    return ans;
}

string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    string ans = "";
    for(int i = 0; i < n; i++){
        char c = nums[i][i];
        ans += c == '0' ? '1' : '0';
    }
    return ans;
}

string findDifferentBinaryString1(vector<string>& nums) {
    int n = nums.size();
    vector<int> searched(pow(2, n));
    for(string i : nums){
        int m = 0;
        for(int j = 0; j < n; j++){ 
            m = m | ((i[j] - '0') << (n - j - 1));
        }
        searched[m] = true;
    }
    for(int i = 0; i < pow(2, n); i++){
        if(!searched[i]){
            return toBinary(i, n);
        }
    }
    return " ";
}

void solve(){
    int n;
    cin >> n;
    vector<string> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << findDifferentBinaryString(nums);
}

int main(void){
    solve();
    return 1;
}
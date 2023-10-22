#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

/*
    NOTE: To solve this problem we can take a greedy approach to calculate all maximum sums of subarrays sizes (1 - n).

    We know that for every valid subarray, the kth index has to be included. Therefore we can conclude that the subarray of size 1 would have a minimum value of k and maximum sum
    of k * 1. This means that when calculating the maxium sums of each subarray size, we have to start at index k and expand outwards.

    The question now is which way should we expand the array. Take for example this array with k = 3:
    1 4 3 7 4 5
          ^
    We start at size 1 with a max value of 7. Then we have to decide whether to move left or right. If we move right, the new minimum would be 4 and therefore the new maximum would
    be 4 * 2 = 8. If we move left, the new minimum would be 3 and the sum would be 3 * 2 = 6. By using a greedy approach we will then choose the right side to expand on. Notice that
    since both of the expanded arrays have the same length, the only way for the sum to be greater is if the minimum number is greater.

    In this case, 4 is greater then 3 so we added 4 into the subarray. We will always expand upon the side which gives the largest minimum number.

    But what if the both the expansion does not change the minimum like for this array:
    1 4 3 2 4 5
          ^
    If this is the case then no matter how we expand the array the answer will remain the same. This means that we can pick any arbritrary side to expand on until a new minimum is
    reached.
*/

int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = nums[k];
    int left = k;
    int right = k;
    int currMin = nums[k];
    while(left > 0 || right < n - 1){
        int l = left > 0 ? min(currMin, nums[left - 1]) : 0;
        int r = right < n - 1 ? min(currMin, nums[right + 1]): 0;
        if(l < r){
            right++;
            currMin = min(currMin, nums[right]);
        }else{
            left--;
            currMin = min(currMin, nums[left]);
        }
        ans = max(ans, currMin * (right - left + 1));
    }
    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << maximumScore(nums, k);
}

int main(void){
    solve();
    return 1;
}
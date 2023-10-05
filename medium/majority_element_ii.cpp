#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

/*
    Boyer-Moore Majority Voting Algorithm; TIME: O(N); SPACE O(1);

    Take a n array of unsorted number. Find if a value appears more than n/2 times.
    Note that if a number A appears more than n/2 times, then the other numbers will have to appear less that n/2 times. That means that if A 
    is in the majority, we can pair A with a different number and at the end there will be a positive count of A left over.
    Using this knowledge, we can start by setting an arbritrary number as A. Then for every unlike number we subtract 1 to its count. 
    If the count reaches zero, that means that every A has been paired off in the subarray[i, j], where i is the first index of A and j is the current index.
    If that is the case, we can disregard subarray[i, j] and continue onwards with A as the current index. By the end of the loop, A will be the majority in the array.

    EXAMPLE:
        [5, 0, 1, 0, 0, 1, 0]
        1. [5, 0] This subarray has an equal number of 5 as other numbers, so it will not affect the final result. Set A as 1.
        2. [1, 0] This subarray is the same, set A as 0.
        3. [0, 1, 0]. The final value for A is 0. Checking through the array 0 does appear more than n / 2 times.

    Looking back, we can see that every other numbers was paired off and we were left with the subarray [0, 1, 0].
    In summary, we check if each subarray has a majority number. If it does not we can remove it from results. What we have left will be the majority number.

    To extend this into numbers that appear more than n/3 times, we can add another number to keep track of. By doing the same process while making sure that
    the number A does not interfere with number B, we will obtain two number at the end which are likely to appear more than n / 3 times.
    We then have to check if they meet the requirements by looping through the array again while counting the number of occurences of these numbers.
*/

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int c1 = 0, c2 = 0, n1 = 0, n2 = 1;
    for(int i = 0; i < n; i++){
        if(n1 == nums[i]){
            c1++;
        }else if(n2 == nums[i]){
            c2++;
        }else if(c1 == 0){
            n1 = nums[i];
            c1 = 1;
        }else if(c2 == 0){
            n2 = nums[i];
            c2 = 1;
        }else{
            c1--;
            c2--;
        }
    }
    cout << n1 << ' ' << n2 << "\n";
    c1 = 0;
    c2 = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == n1) c1++;
        if(nums[i] == n2) c2++;
    }
    nums.clear();
    if(c1 > n / 3) nums.push_back(n1);
    if(c2 > n / 3) nums.push_back(n2);
    return nums;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> ans = majorityElement(nums);
    for(int i : ans){
        cout << i << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
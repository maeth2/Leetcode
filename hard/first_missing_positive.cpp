#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

/*
    **NOTE**
    Take an array = [1, 2, -1, 4, 6]. The longest consecutive value will be from 1 to 5. 
    We cannot have more indexes than slots availible in the array. This means that within the array if there are ignored values 
    or if there are values outside of this range, there will be a consecutive number missing.

    If we have an sorted array of size n, the maximum number of consecutive numbers that can be stored in it will be n.

    For Example, if I have an array of size 7, the sorted array with consecutive numbers would be
        [1, 2, 3, 4, 5, 6, 7]

    Using this logic, we can also determine that each index in the sorted array will correlate with its value.
        [0] = 1;
        [1] = 2;
        [2] = 3;
        ...
    
    Therefore to find the first missing value of an sorted consecutive array we can simply find the first index that does not match its value - 1.

    When sorting the array there are a few things to note:
        1. If the value is greater than the maximum range of consecutive numbers, we can ignore it.
        2. If the value is smaller than 1, we can ignore it.
        3. Once we swap a value, perform the same checks for the new value.

    In order to sort the array we can loop through the unsorted array and swap each value to it's corresponding index. This can be done in O(N) time
    as for each swap, one more value is put in the correct spot, leaving 1 less value to sort:
        array = [1, -1, 5, 2]
        i = 0; [1, -1, 5, 2]; 1 = [0]; This is in the correct spot.
        i = 1; [1, -1, 5, 2]; -1 < 1; Ignore this value since it is not positive.
        i = 2; [1, -1, 5, 2]; 5 > n - 1; 5 is outside of the maximum range of consecutive numbers, ignore.
        i = 3; [1, 2, 5, -1]; 2 = [1]; Swap the current index with [1].
        i = 3; [1, 2, 5, -1]; -1 < 1; Ignore.

        [1, 2, 5, -1] The first missing value is 3.
    
    Note that we could have predicted that the value would be less than n because the maximum range of the missing number would be from (1 to n).

    If all values were in the correct place than the missing value would be n + 1.
*/

int firstMissingPositive(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++){
        while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]){
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }
    for(int i = 0; i < nums.size(); i++){
        if(i != nums[i] - 1){
            return i + 1;
        }
    }
    return nums.size() + 1;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << firstMissingPositive(nums);
}

int main(void){
    solve();
    return 1;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;
using ll = long long;

/*
    CONSTRAINTS:
        i < j < k
        num[i] < num[k] < num[j]

    In order to solve we have to keep track of 2 variables:
        1. The largest number to represent num[j]
        2. The second largest number to represent num[k]
    
    We also have to make sure that j < k. To do that we will loop from back to front and keep track of the numbers in a stack.
    We can then check if the current number is greater than the previous numbers. Remove all previous numbers smaller than the current one
    from the stack and assign the last number as num[k]. This ensures that we will always have the largest num[k].

    This helps us ensure that n[j] is always greater than n[k] while making sure that j come before k.

    We can check for num[i] by checking if the current number is smaller than num[k]. If it is, we know that there is a 132 pattern.

    EXAMPLE:
    a = 1 5 3 4

    We will start from the back and push 4 into the stack.

    stack = 4
    a = 1 5 3

    Since 3 is not greater than 4, we will continue

    a = 1 5

    5 is greater than 4 so we set 4 as the num[k]

    a = 1
    1 is smaller than 4 (num[k]) therefore 1 < 4 < 5 or num[i] < num[k] < num[5]. A 132 pattern is present in this array.

    Essentially, we all we are doing is searching iteratively for the largest case of num[j] > num[k]. Then we can store it and check it with num[i].
*/

bool find132pattern(vector<int>& nums) {
    if(nums.size() < 3) return false;
    int kNumber = INT32_MIN;
    stack<int> k;
    for(int i = nums.size() - 1; i >= 0; i--){
        int number = nums[i];

        if(number < kNumber){
            return true;
        }

        while(!k.empty() && k.top() < number){
            kNumber = k.top();
            k.pop();
        }
        k.push(number);
    }
    return false;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << find132pattern(nums);
}

int main(void){
    solve();
    return 1;
}
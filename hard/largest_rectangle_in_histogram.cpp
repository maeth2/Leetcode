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
    NOTE: To solve this problem we can use a stack to keep track of the heights.

    For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle. 
    If we calculate the such area for every bar ‘x’ and find the maximum of all areas, our task is done. 

    To do this, we have to keep a stack of bar heights so we can find the first instance where 'x' is not the smallest bar.

    We will iterate through the array. If the current bar is greater than the last one, we will add it to the stack. If not, then we will
    loop through the stack and checking the area of the rectangle using the height and the distance from the top index as the width
    (We can do this since the stack will always be in descending order) until the height is less than the current bar.
*/

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int ans = -1;
    int index = 0;
    for(int i = 0; i <= heights.size(); i++){
        int h = (i == heights.size() ? -1 : heights[i]);
        cout << st.size() << "\n";
        if(st.empty() || h >= heights[st.top()]){
            st.emplace(i);
        }else{
            int a = st.top();
            st.pop();
            ans = max(ans, heights[a] * (st.empty() ? i : i - st.top() - 1));
            i--;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }
    cout << largestRectangleArea(heights);
}

int main(void){
    solve();
    return 1;
}
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

    We will iterate through the array. If the current bar is greater than the last one, we will add it to the stack. If not, then we will
    loop through the stack and checking the area of the rectangle using the top stack as the height and the distance from the top index to the current as the width
    (We can do this since the stack will always be in descending order) until the height is less than the current bar.

    Example; This is a stack with size 5. The current number is 2. Lets represent the top of the stack as i and the current index as j.

            O                   |
          | O                 O O
        | | O               | O O
      | | | O X           | | O O X
    | | | | O X         | | | O O X     
            i j               i   j     

            |                   |
          | |                 | |
        O O O               | | |
      | O O O X           O O O O X
    | | O O O X         | O O O O X     
        i     j           i       j

    As you can see, the stack is in decreasing order, meaning the top of the stack is always larger or equal than the one behind it. For a given range of bars, the height is determined
    by the height of the shortest bar. Therefore for each element in the stack, there will always be a rectangle of height[i] and width (j - i).
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
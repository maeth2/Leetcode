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
    NOTE: We can imagine this problem as an extension of the largest rectangle in a histogram. 

    For a rectangle to be valid, every cell has to be a 1. To solve this problem, we have to find a way to keep track of all rectangles we have solved.
    Here is where the Largest Rectangle in a histogram comes in.

    Imagine that each column is a bar, the height of the bar will be equal to the number of successive 1s (or the first instance of a 0) in the column starting from row. 

    We can calculate this by going through every row, increasing the height of the column by one if the cell is 1 and setting the height to 0 if the cell is 0
    (Remember the height is equal to the first instance of a 0). We will then run the largest rectangle algorithm to find all rectangles from the current row.

    We are essentially iterating through each row and calculating each bar using the current row as the base. The height of said bar will always be the
    largest number of consecutive 1s from the base.

    Alternatively, we can imagine each column as a rectangle of width 1 and the row as the height, the height will be the first instance of 0 from the base.

    Here is an example using a matrix of size 4 by 5:

    1 0 1 0 0  
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0

    Once we loop through each row and update the heights, the new matrix will come to this.

    1 0 1 0 0  
    2 0 2 1 1
    3 1 3 2 2
    4 0 0 3 0
*/

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> height(m);
    int ans = -1;
    for(int i = 0; i < n; i++){
        stack<int> st;
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == '0'){
                height[j] = 0;
            }else{
                height[j] += 1;
            }
        }
        for(int j = 0; j <= m; j++){
            int h = (j == m ? -1 : height[j]);
            if(st.empty() || h >= height[st.top()]){
                st.emplace(j);
            }else{
                int tp = st.top();
                st.pop();
                ans = max(ans, height[tp] * (st.empty() ? j : j - st.top() - 1));
                j--;
            }
        }
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    cout << maximalRectangle(matrix);
}

int main(void){
    solve();
    return 1;
}
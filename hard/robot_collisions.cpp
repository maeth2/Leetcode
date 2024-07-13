#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;
using ll = long long;

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    vector<int> index(n);
    for(int i = 0; i < n; i++){
        index[i] = i;
    }

    sort(index.begin(), index.end(),
        [&](int a, int b) {return positions[a] < positions[b];}
    );

    bool combine = true;
    stack<int> st;
    for(int i : index){
        if(directions[i] == 'R'){
            st.push(i);
        }else{
            while(st.size() > 0 && healths[st.top()] < healths[i] && directions[st.top()] == 'R'){
                st.pop();
                healths[i]--;
            }
            if(st.size() == 0 || directions[st.top()] == 'L'){
                st.push(i);
            }else if(healths[st.top()] == healths[i]){
                st.pop();
            }else{
                healths[st.top()]--;
            }
        }
    }

    vector<int> ans = {};
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        ans[i] = healths[ans[i]];
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> positions(n);
    vector<int> healths(n);
    string directions = "";
    for(int i = 0; i < n; i++){
        cin >> positions[i];
    }
    for(int i = 0; i < n; i++){
        cin >> healths[i];
    }
    cin >> directions;
    vector<int> ans = survivedRobotsHealths(positions, healths, directions);
    for(int i : ans){
        cout << i << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
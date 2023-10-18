#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

/*
    NOTE: To solve this problem we can take advantage of the fact that courses can be ran at the same time.

    In order to complete a course, you would first need to complete the prerequisite. If there are more than one prerequisite, the fastest way to complete them is to do them
    simultaneously. By doing so, the fastest you can complete all the prequisites would be the longest timing among them.

    RECURSIVE APPROACH:
    This allows us to break the problem down into smaller sub-problems. For each course, we will have to check and compare all the pre-requisite courses.  We will keep recursively
    checking them until the course no longer has any pre-requisites, returning the course length. Once all pre-requisites have been found, the fastest timing to complete the course 
    would be the (course length + longest prequisite timing). 

    For instances where there are multiple paths from Course A to Course B, the calculations will still be correct:
        For paths A -> B and A -> C -> B. 

        Using our function, we will always check A first as it has no pre-requisites. 
        Once we have checked A, we will then update C as all its pre-requisites has been met.
        Finally we will compare A and C and update B.

        Since we are keeping track of if all pre-requisites has been met, we will not have to worry about multple paths.

    Using this approach, we will have to start from courses with no outgoing relations and recurse back (There may be more then 1 of these starting course).
    
    TOPOLOGICAL APPROACH:
    The idea for this approach remains the same, however the difference is that we calculate each point in a more bfs method.

    To start out, we have to keep track of how many pre-requisites each course has. We will then start at courses with no pre-requisites. As explained above, we set the course
    timing as the course length. As we explore each course, we will update the parent using its timing. If the current time is greater then the parent longest pre-requisite, 
    we will set the max as the current time. Then, we will subtract one from the parents pre-requisite count. If the count reaches 0, it means that all the pre-requisites has been 
    checked. We will then set the fastest time to complete the course (course timing) as (course length + longest prequisite timing) and push it to the queue (This ensures that each
    course searched already has all pre-requisites checked).

    Once we have checked all the courses, the fastest timing will be the longest timing of all the courses.
*/

int recurse(int i, vector<vector<int>> &graph, vector<int> &time, vector<int> &maxes){
    int mx = 0;
    if(maxes[i] != -1) return maxes[i];
    for(int j : graph[i]){
        mx = max(mx, recurse(j, graph, time, maxes));
    }
    maxes[i] = time[i] + mx;
    return maxes[i];
}

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<int> outDegree(n);
    vector<int> maxes(n, -1);
    vector<vector<int>> graph(n);
    for(int i = 0; i < relations.size(); i++){
        outDegree[relations[i][0] - 1]++;
        graph[relations[i][1] - 1].push_back(relations[i][0] - 1);
    }
    int mx = -1;
    for(int i = 0; i < n; i++){
        if(outDegree[i] == 0){
            mx = max(mx, recurse(i, graph, time, maxes));
        }
    }
    return mx;
}

int minimumTime1(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<int> inDegree(n);
    vector<int> maxDegree(n);
    vector<vector<int>> graph(n);
    for(int i = 0; i < relations.size(); i++){
        inDegree[relations[i][1] - 1]++;
        graph[relations[i][0] - 1].push_back(relations[i][1] - 1);
    }
    queue<int> pq;
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0) pq.push(i);
    }
    int mx = -1;
    while(!pq.empty()){
        int i = pq.front();
        pq.pop();
        int t = time[i] + maxDegree[i];
        mx = max(mx, t);
        for(int j : graph[i]){
            inDegree[j]--;
            maxDegree[j] = max(maxDegree[j], t);
            if(inDegree[j] == 0) pq.push(j);
        }
    }
    return mx;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> relations(m, vector<int>(2));
    vector<int> time(n);
    for(int i = 0; i < m; i++){
        cin >> relations[i][0] >> relations[i][1];
    }
    for(int i = 0; i < n; i++){
        cin >> time[i];
    }
    cout << minimumTime(n, relations, time);
}

int main(void){
    solve();
    return 1;
}
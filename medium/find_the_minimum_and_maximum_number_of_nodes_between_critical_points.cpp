#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    int minDist = INT32_MAX;
    int prev = -1;
    int first = -1;
    ListNode* current = head->next;
    int prevVal = head->val;
    int i = 1;
    while(current->next != nullptr){
        int currentVal = current->val;
        int nextVal = current->next->val;
        if((currentVal > nextVal && currentVal > prevVal) || (currentVal < nextVal && currentVal < prevVal)){
            if(prev != -1){
                minDist = min(minDist, i - prev);
            }
            if(first == -1){
                first = i;
            }
            prev = i;
        }
        prevVal = current->val;
        current = current->next;
        i++;
    }
    if(minDist == INT32_MAX){
        return {-1, -1};
    }else{
        int maxDist = prev - first;
        return {minDist, maxDist};
    }
}

void solve(){
    int n, v;
    cin >> n >> v;
    ListNode* head;
    head = new ListNode(v);
    ListNode *prev = head;
    for(int i = 1; i < n; i++){
        cin >> v;
        ListNode* l = new ListNode(v);
        prev->next = l;
        prev = l;
    }
    vector<int> ans = nodesBetweenCriticalPoints(head);
    for(int i : ans){
        cout << i << ' ';
    }
}

int main(void){
    solve();
    return 1;
}
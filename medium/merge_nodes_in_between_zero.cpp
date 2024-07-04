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

ListNode* mergeNodes(ListNode* head) {
    vector<ListNode*> a;
    ListNode *next = head->next;
    int sum = 0;
    while(next != nullptr){
        int v = next->val;
        if(v == 0){
            a.push_back(new ListNode(sum));
            sum = 0;
        }else{
            sum += v;
        }
        next = next->next;
    }
    ListNode* ans = a[0];
    next = ans;
    for(int i = 1; i < a.size(); i++){
        next->next = a[i];
        next = a[i];
    }
    return ans;    
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
    ListNode *next = mergeNodes(head);
    while(next != nullptr){
        cout << next->val << ' ';
        next = next->next;
    }
}

int main(void){
    solve();
    return 1;
}
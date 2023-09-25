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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* n1 = l1;
    ListNode* n2 = l2;
    vector<ListNode*> ans;
    int i = 0;
    while(n1 != nullptr || n2 != nullptr){
        int val = i;
        if(n1 != nullptr) val += n1->val;
        if(n2 != nullptr) val += n2->val;
        i = val / 10;
        val = val - (val / 10) * 10;
        ListNode* node = new ListNode(val);
        ans.push_back(node);
        if(n1 != nullptr) n1 = n1->next;
        if(n2 != nullptr) n2 = n2->next;
    }
    if(i != 0){
        ListNode* node = new ListNode(i);
        ans.push_back(node);  
    }
    for(int i = 0; i < ans.size() - 1; i++){
        ans[i]->next = ans[i + 1];
    }
    return ans[0];
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<ListNode*> l1(n);
    vector<ListNode*> l2(m);
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        ListNode* node = new ListNode(val);
        l1[i] = node;
    }
    for(int i = 0; i < n - 1; i++){
        l1[i]->next = l1[i + 1];
    }
    for(int i = 0; i < m; i++){
        int val;
        cin >> val;
        ListNode* node = new ListNode(val);
        l2[i] = node;
    }
    for(int i = 0; i < m - 1; i++){
        l2[i]->next = l2[i + 1];
    }
    ListNode* ans = addTwoNumbers(l1[0], l2[0]);
    while(ans != nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << "\n";
}

int main(void){
    solve();
    return 1;
}
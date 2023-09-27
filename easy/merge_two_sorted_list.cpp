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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* n1 = list1;
    ListNode* n2 = list2;
    ListNode* prev = nullptr;
    ListNode* ans = nullptr;
    if(n1->val <= n2->val){
        prev = n1;
        n1 = n1->next;
    }else{
        prev = n2;
        n2 = n2->next;
    }
    ans = prev;
    while(n1 != nullptr || n2 != nullptr){
        if(n1 == nullptr){
            prev->next = n2;
            n2 = n2->next;
        }else if(n2 == nullptr){
            prev->next = n1;
            n1 = n1->next;
        }else if(n1->val <= n2->val){
            prev->next = n1;
            n1 = n1->next;
        }else if(n2->val < n1->val){
            prev->next = n2;
            n2 = n2->next;
        }
        prev = prev->next;
    }
    return ans;
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
    ListNode* ans = mergeTwoLists(l1[0], l2[0]);
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
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

//Commonly Accepted O(1) Space Complexity
ListNode* reverseKGroup1(ListNode* head, int k) {
    int length = 0;
    ListNode* ans;
    ListNode* curr = head;
    ListNode* prev;
    ListNode* next;
    ListNode* temp = nullptr;
    ListNode* last;
    while(curr != nullptr){
        length++;
        curr = curr->next;
    }
    curr = head;
    for(int i = 0; i < length / k; i++){
        last = curr;
        prev = nullptr;
        for(int j = 0; j < k; j++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(temp != nullptr){
            temp->next = prev;
        }
        temp = last;
        if(i == 0){
            ans = prev;
        }
    }
    if(length % k != 0){
        last->next = curr;
    }
    return ans;
}

//O(N) Space Complexity
ListNode* reverseKGroup(ListNode* head, int k) {
    vector<ListNode*> l;
    ListNode* next = head;
    while(next != nullptr){
        l.push_back(next);
        next = next->next;
    }
    for(int i = 0; i < l.size(); i+=k){
        if(i + k - 1 >= l.size()) break;
        for(int j = 0; j < k / 2; j++){
            ListNode* temp = l[i + j];
            l[i + j] = l[i + k - j - 1];
            l[i + k - j - 1] = temp;
        }
    }
    for(int i = 0; i < l.size() - 1; i++){
        l[i]->next = l[i + 1];
    }
    l[l.size() - 1]->next = nullptr;
    return l[0];
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ListNode*> l(n);
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        ListNode* node = new ListNode(val);
        l[i] = node;
    }
    for(int i = 0; i < n - 1; i++){
        l[i]->next = l[i + 1];
    }
    ListNode* ans = reverseKGroup(l[0], k);
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
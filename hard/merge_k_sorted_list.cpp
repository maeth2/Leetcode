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

void binary_insert(vector<ListNode*> &nums, ListNode* i){
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(i->val == nums[middle]->val){
            left = middle;
            break;
        }else if(i->val > nums[middle]->val){
            left = middle + 1;
        }else if(i->val < nums[middle]->val){
            right = middle - 1;
        }
    }
    nums.insert(nums.begin() + left, i);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0){
        return nullptr;
    }
    vector<ListNode*> sl;
    for(ListNode* l : lists){
        ListNode *n = l;
        while(n != nullptr){
            if(sl.size() == 0){
                sl.push_back(n);
            }else{
                binary_insert(sl, n);
            }
            if(n->next == nullptr){
                break;
            }
            n = n->next;
        }
    }
    for(int i = 0; i < sl.size(); i++){
        sl[i]->next = nullptr;
    }
    for(int i = 0; i < sl.size() - 1; i++){
        sl[i]->next = sl[i + 1];
    }
    if(sl.size() == 0){
        return nullptr;
    }
    return sl[0];
}

void solve(){
    int n;
    cin >> n;
    vector<ListNode*> li;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        vector<ListNode*> a(m);
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            ListNode* node = new ListNode(val);
            a[j] = node;
        }
        for(int j = 0; j < m - 1; j++){
            a[j]->next = a[j + 1];
        }
        li.push_back(a[0]);
    }
    ListNode* ans = mergeKLists(li);
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
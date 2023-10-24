#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> largestValues(TreeNode* root) {
    queue<pair<TreeNode*, int>> pq;
    vector<int> ans;
    if(root == nullptr) return ans;
    pq.emplace(root, 0);
    ans.push_back(root->val);
    while(!pq.empty()){
        TreeNode* i = pq.front().first;
        int row = pq.front().second;
        pq.pop();
        TreeNode* l = i->left;
        TreeNode* r = i->right;
        if(ans.size() == row) ans.push_back(INT_MIN);
        ans[row] = max(ans[row], i->val);
        if(l != nullptr) pq.emplace(l, row + 1);
        if(r != nullptr) pq.emplace(r, row + 1);
    }
    return ans;
}

int main(void){
    return 1;
}
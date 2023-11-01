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

void printBinaryTree(TreeNode* root){
    queue<TreeNode*> pq;
    pq.push(root);
    while(!pq.empty()){
        TreeNode *node = pq.front();
        pq.pop();
        cout << node->val << ' ';
        if(node->left != nullptr) pq.emplace(node->left);
        if(node->right != nullptr) pq.emplace(node->right);
    }
    cout << "\n";
}

void printFullBinaryTree(vector<vector<string>> tree){
    for(vector<string> s : tree){
        for(string i : s) cout << i << " ";
    }
    cout << "\n";
}

void recurse(TreeNode* node, int &prev, int &count, vector<int> &mode, int &mx){
    if(node == nullptr) return;
    recurse(node->left, prev, count, mode, mx);
    if(node->val == prev){
        count++;
    }else{
        count = 1;
        prev = node->val;
    }
    if(count > mx){
        mode = {};
        mode.push_back(node->val);
    }else if(count == mx){
        mode.push_back(node->val);
    }
    recurse(node->right, prev, count, mode, mx);
}

vector<int> findMode(TreeNode* root) {
    vector<int> ans;
    int mx = 0;
    int prev = 0;
    int count = 0;
    recurse(root, prev, count, ans, mx);
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<string> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<string>> tempTree(2);
    tempTree[0].push_back(nums[0]);
    int index = 1;
    int h = 1;
    int c = 0;
    int i = 1;
    while(i < n - 1){
        if(c * 2 == pow(2, h)){
            c = 0;
            h++;
            vector<string> j;
            tempTree.push_back(j);
        }
        tempTree[h].push_back(tempTree[h - 1][c] != "null" ? nums[i++] : "null");
        tempTree[h].push_back(tempTree[h - 1][c] != "null" ? nums[i++] : "null");
        c++;
    }
    
    h++;
    vector<vector<TreeNode*>> tree(h + 1);
    TreeNode *root = new TreeNode(stoi(tempTree[0][0]));
    tree[0].push_back(root);
    for(int i = 1; i < h; i++){
        for(int j = 0; j * 2 < pow(2, i); j++){
            if(tempTree[i - 1][j] != "null"){
                string l = tempTree[i][j * 2];
                string r = tempTree[i][j * 2 + 1];
                TreeNode *left = (l == "null" ? nullptr : new TreeNode(stoi(l)));
                TreeNode *right = (r == "null" ? nullptr : new TreeNode(stoi(r)));
                if(tree[i - 1][j] != nullptr) tree[i - 1][j]->left = left;
                if(tree[i - 1][j] != nullptr) tree[i - 1][j]->right = right;
                tree[i].push_back(left);
                tree[i].push_back(right);
            }else{
                tree[i].push_back(nullptr);
                tree[i].push_back(nullptr);
            }
        }
    }

    vector<int> ans = findMode(root);
    for(int i : ans) cout << i << ' ';
}

int main(void){
    solve();
    return 1;
}
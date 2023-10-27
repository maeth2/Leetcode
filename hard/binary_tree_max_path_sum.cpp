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
    NOTE: The specification of this problem states that for any given path, no backtracking is allowed. This means that if you explore both children of a node, you can no longer
    explore the parent. 
    
    For this problem we have to account for 7 cases:
        Case #1:
            Current Node is the root node and add the maximum sum of the left child.

        Case #2:
           Current Node is the root node and add the maximum sum of the right child.

        Case #3:
            Current Node is the root node and don't add the children.

        Case #4:
            Current Node is not the root node and add the maximum sum of the left child.

        Case #5:
            Current Node is not the root node and add the maximum sum of the right child.

        Case #6:
            Current Node is not the root node and don't add the children.
        
        Case #7:
            Current Node is not the root node and add both the children.

    Notice that for case 1-3 we are still including the parent. However for case 4-7 we will not include the parent. 
    We can use basic recursion to find the maximum for cases 1-3, however for cases 4-7 we need to keep a running maximum of all nodes.

    The final answer will be the max of the running maximum and the maxmimum of the recursion.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int recurse(TreeNode *node, int &mx){
    if(node == nullptr) return 0;
    int ans = -1001;
    int l = recurse(node->left, mx);
    int r = recurse(node->right, mx);
    int a = max(max(node->val + l, node->val + r), node->val);
    mx = max(mx, a);
    ans = max(ans, a);
    mx = max(mx, node->val + l + r);
    return ans;
}

int maxPathSum(TreeNode* root) {
    int ansNode = -1001;
    int ansRoot = recurse(root, ansNode);
    return max(ansNode, ansRoot);
}

void printBinaryTree(TreeNode* root){
    queue<TreeNode *> pq;
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

    //printBinaryTree(root);
    cout << maxPathSum(root);
}

int main(void){
    solve();
    return 1;
}
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void travelsal(TreeNode* root, unordered_map<int, int> &mp) {
    if(!root)
        return;
    travelsal(root->left, mp);
    mp[root->val] += 1;
    travelsal(root->right, mp);
}

int Solution::solve(TreeNode* A, TreeNode* B) {
    unordered_map<int, int> mp;
    travelsal(A, mp);
    travelsal(B, mp);
    int mod = 1000000007;
    long ans = 0;
    for(auto it: mp) {
        if(it.second==2) {
            ans = (ans%mod + (long)it.first%mod)%mod;
        }
    }
    return ans;
}

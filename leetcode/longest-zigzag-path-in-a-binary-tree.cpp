/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int dis, int &maxi, bool left) {
        maxi = max(maxi, dis);
        if(root->left) {
            if(left) {
                dfs(root->left, 1, maxi, true);
            } else {
                dfs(root->left, dis + 1, maxi, true);
            }
        }
        if(root->right) {
            if(left) {
                dfs(root->right, dis + 1, maxi, false);
            } else {
                dfs(root->right, 1, maxi, false);
            }
        }
    }
    int longestZigZag(TreeNode* root) {
        int maxi = 0;
        if(!root)
            return 0;
        if(!root->left and !root->right) {
            return 0;
        }
        if(root->left)
            dfs(root->left, 1, maxi, true);
        if(root->right)
            dfs(root->right, 1, maxi, false);
        return maxi;
    }
};
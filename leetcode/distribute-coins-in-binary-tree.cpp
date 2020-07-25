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
    int distributeCoinsUtil(TreeNode* root, int &ans) {
        if(root == NULL)
            return 0;
        int l = distributeCoinsUtil(root->left, ans);
        int r = distributeCoinsUtil(root->right, ans);
        ans += abs(l) + abs(r);
        return root->val + l + r - 1;
    }
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        distributeCoinsUtil(root, ans);
        return ans;
    }
};
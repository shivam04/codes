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
    void findBottomLeftValueUtil(TreeNode* root, int lvl, int *maxlvl, int *ans) {
        if(root == NULL)
            return;
        if(lvl > *maxlvl) {
            *ans = root->val;
            *maxlvl = lvl;
        }
        findBottomLeftValueUtil(root->left, lvl+1, maxlvl, ans);
        findBottomLeftValueUtil(root->right, lvl+1, maxlvl, ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxlevel = -1; 
        int ans = 0;
        findBottomLeftValueUtil(root, 0, &maxlevel, &ans);
        return ans;
    }
};
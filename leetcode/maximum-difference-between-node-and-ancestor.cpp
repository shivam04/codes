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
    int maxAncestorDiffUtil(TreeNode* root, int mini, int maxi) {
        int p = abs(maxi-mini);
        if(!root)
            return 0;
        if(root->left){
            p = max(p, maxAncestorDiffUtil(root->left, min(root->left->val, mini), max(root->left->val,maxi)));
        }
        if(root->right){
            p = max(p, maxAncestorDiffUtil(root->right, min(root->right->val, mini), max(root->right->val,maxi)));
        }
        return p;
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        return maxAncestorDiffUtil(root, root->val, root->val);
    }
};
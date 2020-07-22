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
    int pruneTreeUtil(TreeNode *root) {
        if(!root)
            return 0;
        if(!root->left and !root->right) {
            return root->val;
        }
        int a = pruneTreeUtil(root->left);
        if(a==0)
            root->left = NULL;
        int b = pruneTreeUtil(root->right);
        if(b==0)
            root->right = NULL;
        return max(a,max(b,root->val));
    }
    TreeNode* pruneTree(TreeNode* root) {
        return pruneTreeUtil(root) ? root : NULL;
    }
};
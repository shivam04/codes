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
        int leftOne = pruneTreeUtil(root->left);
        int rightOne = pruneTreeUtil(root->right);
        if(leftOne==0) root->left = NULL;
        if(rightOne==0) root->right = NULL;
        return max(leftOne,max(rightOne, root->val));
    }
    TreeNode* pruneTree(TreeNode* root) {
        pruneTreeUtil(root);
        return root;
    }
};
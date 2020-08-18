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
    TreeNode *kthSmallestUtil(TreeNode* root, int &count, int k) {
        if(!root)
            return root;
        TreeNode *left = kthSmallestUtil(root->left, count, k);
        if(left != NULL)
            return left;
        count++;
        if (count == k) 
            return root; 
        return kthSmallestUtil(root->right, count, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode *node = kthSmallestUtil(root, count, k);
        return node->val;
    }
};
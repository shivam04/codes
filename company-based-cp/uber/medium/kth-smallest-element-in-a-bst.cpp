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
    TreeNode* kthSmallestUtil(TreeNode* root, int k, int &count) {
        if (root == nullptr) {
            return root;
        }
        TreeNode *left = kthSmallestUtil(root->left, k, count);
        if(left != nullptr)
            return left;
        count++;
        if (count == k) {
            return root;
        }
        return kthSmallestUtil(root->right, k, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode* node = kthSmallestUtil(root, k, count);
        return node == nullptr? -1 : node->val;
    }
};
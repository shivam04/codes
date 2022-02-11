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
    void goodNodesUtil(TreeNode* root, int maxi, int &cnt) {
        if(!root)
            return;
        if(root->val>=maxi) cnt++;
        goodNodesUtil(root->left, max(maxi, root->val), cnt);
        goodNodesUtil(root->right, max(maxi, root->val), cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        goodNodesUtil(root, -1000000000, cnt);
        return cnt;
    }
};
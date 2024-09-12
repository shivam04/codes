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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == nullptr)
            return {};
        unordered_set<int> delSet(to_delete.begin(), to_delete.end());
        queue<TreeNode*> q;
        vector<TreeNode*> ans;
        q.push(root);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                if (delSet.find(node->left->val) != delSet.end()) {
                    node->left = nullptr;
                }
            }

            if (node->right) {
                q.push(node->right);
                if (delSet.find(node->right->val) != delSet.end()) {
                    node->right = nullptr;
                }
            }

            if (delSet.find(node->val) != delSet.end()) {
                if (node->left) ans.push_back(node->left);
                if (node->right) ans.push_back(node->right);
            }
        }

        if (delSet.find(root->val) == delSet.end()) {
            ans.push_back(root);
        }

        return ans;
    }
};
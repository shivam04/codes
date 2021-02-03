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
    void largestValuesUtil(TreeNode* root, vector<int> &res, int lvl) {
        if(!root)
            return;
        if(lvl == res.size()) {
            res.push_back(root->val);
        }
        res[lvl] = max(res[lvl], root->val);
        largestValuesUtil(root->left, res, lvl+1);
        largestValuesUtil(root->right, res, lvl+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        largestValuesUtil(root, res, 0);
        return res;
    }
};
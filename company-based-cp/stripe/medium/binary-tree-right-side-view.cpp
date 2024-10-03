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
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> cq, nq;
        vector<int> ans;
        if(!root)
            return ans;
        cq.push_back(root);
        ans.push_back(cq.back()->val);
        while (!cq.empty()) {
            TreeNode* node = cq.front();
            cq.pop_front();
            if(node->left)
                nq.push_back(node->left);
            if(node->right)
                nq.push_back(node->right);
            if(cq.empty() and !nq.empty()) {
                swap(cq, nq);
                ans.push_back(cq.back()->val);
            }
        }
        return ans;
    }
};
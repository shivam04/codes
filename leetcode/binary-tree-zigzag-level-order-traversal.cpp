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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        stack<TreeNode*> currentlevel; 
        stack<TreeNode*> nextlevel; 
        currentlevel.push(root);
        vector<int> level;
        int ltor = 1;
        while(!currentlevel.empty())  {
            TreeNode *node = currentlevel.top();
            currentlevel.pop();
            if(ltor) {
                if(node->left)
                    nextlevel.push(node->left);
                if(node->right)
                    nextlevel.push(node->right);
            } else {
                if(node->right)
                    nextlevel.push(node->right);
                if(node->left)
                    nextlevel.push(node->left);
            }
            level.push_back(node->val);
            if(currentlevel.empty()) {
                ltor = !ltor;
                ans.push_back(level);
                level.clear();
                swap(currentlevel, nextlevel);
            }
        }
        return ans;
    }
};
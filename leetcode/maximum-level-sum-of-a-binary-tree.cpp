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
    int maxLevelSum(TreeNode* root) {
        if(!root)
            return -1;
        queue<pair<TreeNode*,int> > q;
        q.push({root,0});
        map<int,int> mp;
        while(!q.empty()) {
            pair<TreeNode*,int> p = q.front();
            q.pop();
            int l = p.second;
            TreeNode* node = p.first;
            mp[l] += node->val;
            if(node->left) {
                q.push({node->left, l+1});
            }
            if(node->right) {
                q.push({node->right, l+1});
            }
        }
        int ansi = 0;
        int ans  = 0;
        for(auto it=mp.begin();it!=mp.end();++it) {
            if(ans < it->second) {
                ans = it->second;
                ansi = it->first;
            }
        }
        return ansi+1;
    }
};
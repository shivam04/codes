/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> parent;
    void dfs(TreeNode* root, TreeNode* par) {
        if(!root)
            return;
        parent[root] = par;
        dfs(root->left, root);
        dfs(root->right, root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        dfs(root, NULL);
        set<TreeNode*> visit;
        visit.insert(target);
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, int> mp;
        mp[target] = 0;
        while(!q.empty()) {
            TreeNode* s = q.front();
            q.pop();
            if(s->left != NULL and visit.find(s->left) == visit.end()) {
                q.push(s->left);
                visit.insert(s->left);
                mp[s->left] = mp[s]+1;
            }
            if(s->right != NULL and visit.find(s->right) == visit.end()) {
                q.push(s->right);
                visit.insert(s->right);
                mp[s->right] = mp[s]+1;
            }
            if(parent[s] != NULL and visit.find(parent[s]) == visit.end()) {
                q.push(parent[s]);
                visit.insert(parent[s]);
                mp[parent[s]] = mp[s]+1;
            }
        }
        
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            if(it->second == K) {
                ans.push_back(it->first->val);
            }
        }
        return ans;
    }
};
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
    unordered_map<TreeNode*, vector<TreeNode*>> g;
    set<TreeNode*> leaves;
    int ans;
    set<TreeNode*> visited;
    void dfs1(TreeNode* root) {
        if(!root)
            return;
        if(!root->left and !root->right) {
            leaves.insert(root);
            return;
        }
        if(root->left) {
            g[root].push_back(root->left);
            g[root->left].push_back(root);
            dfs1(root->left);
        }
        if(root->right) {
            g[root].push_back(root->right);
            g[root->right].push_back(root);
            dfs1(root->right);
        }
    }
    void dfs2(TreeNode* u, int dis, int td) {
        visited.insert(u);
        if(leaves.count(u) and dis<=td and dis>0) {
            ans+=1;
            return;
        }
        if(dis > td) {
            return;
        }
        for(auto v : g[u]) {
            if(!visited.count(v))
                dfs2(v, dis+1, td);
        }
    }
    int countPairs(TreeNode* root, int distance) {
        g.clear();
        dfs1(root);
        ans = 0;
        visited.clear();
        for(auto it = leaves.begin(); it!=leaves.end();++it) {
            dfs2(*it, 0, distance);
            visited.clear();
        }
        return ans/2;
    }
};
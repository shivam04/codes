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
    int res;
    map <TreeNode*, TreeNode*> parent;
    void solve(TreeNode* root, TreeNode* par = NULL) {
        if(!root)
            return;
        if(par and parent[par] && parent[par]->val % 2 == 0) {
            res += root->val;
        }
        parent[root] = par;
        solve(root->left, root);
        solve(root->right, root);
    }
    int sumEvenGrandparent(TreeNode* root) {
        res = 0;
        parent.clear();
        solve(root);
        return res;
    }
};
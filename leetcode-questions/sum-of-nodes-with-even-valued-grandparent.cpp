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
    int res;
    map <TreeNode*, TreeNode*> parent;
    void solve(TreeNode* root, TreeNode* par) {
        if(!root)
            return;
        if(par and parent[par] and parent[par]->val%2==0) {
            res += root->val;
        }
        parent[root] = par;
        solve(root->left, root);
        solve(root->right, root);
    }
    int sumEvenGrandparent(TreeNode* root) {
        res = 0;
        parent.clear();
        solve(root, NULL);
        return res;
    }
};
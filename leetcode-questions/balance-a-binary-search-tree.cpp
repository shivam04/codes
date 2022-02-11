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
    void storeBSTNodes(TreeNode* root, vector<TreeNode *> &nodes) {
        if(!root)
            return;
        storeBSTNodes(root->left, nodes);
        nodes.push_back(root);
        storeBSTNodes(root->right, nodes);
    }
    TreeNode* buildTreeUtil(vector<TreeNode *> &nodes, int s, int e) {
        if(s>e)
            return NULL;
        int m = (s+e)/2;
        TreeNode* root = nodes[m];
        root->left = buildTreeUtil(nodes, s, m-1);
        root->right = buildTreeUtil(nodes, m+1, e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> nodes; 
        storeBSTNodes(root, nodes);
        int n = nodes.size(); 
        return buildTreeUtil(nodes, 0, n-1); 
    }
};
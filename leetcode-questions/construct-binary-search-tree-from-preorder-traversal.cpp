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
    TreeNode* makeTree(TreeNode* root, int val){
        if(root == NULL) return new TreeNode(val);
        if(root->val > val) root->left = makeTree(root->left, val);
        else root->right = makeTree(root->right, val);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i=0;i<preorder.size();i++)
            root = makeTree(root, preorder[i]);
        return root;
    }
};
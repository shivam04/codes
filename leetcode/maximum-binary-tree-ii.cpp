class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(!root) {
            return new TreeNode(val);
        }
        if(val > root->val) {
            TreeNode* insertNode = new TreeNode(val);
            insertNode->left = root;
            return insertNode;
        } else {
            root->right = insertIntoMaxTree(root->right, val);
        }
        return root;
    }
};
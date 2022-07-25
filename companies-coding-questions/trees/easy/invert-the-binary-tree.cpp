/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* invertTreeUtil(TreeNode *root) {
    if(root==NULL)
        return NULL;
    TreeNode* temp = root->left;
    root->left = invertTreeUtil(root->right);
    root->right = invertTreeUtil(temp);
    return root;
}
TreeNode* Solution::invertTree(TreeNode* A) {
    TreeNode* aa = invertTreeUtil(A);
    return aa;
}

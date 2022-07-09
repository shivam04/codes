/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void preorderTraversalUtil(TreeNode* root, vector<int> &ans) {
    if(root==NULL)
        return;
    ans.push_back(root->val);
    preorderTraversalUtil(root->left, ans);
    preorderTraversalUtil(root->right, ans);
}
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    preorderTraversalUtil(A, ans);
    return ans;
}

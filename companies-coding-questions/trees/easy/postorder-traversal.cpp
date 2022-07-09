/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void postorderTraversalUtil(TreeNode* root, vector<int> &ans) {
    if(root==NULL)
        return;
    postorderTraversalUtil(root->left, ans);
    postorderTraversalUtil(root->right, ans);
    ans.push_back(root->val);
}
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    postorderTraversalUtil(A, ans);
    return ans;
}

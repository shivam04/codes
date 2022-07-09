/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorderTraversalUtil(TreeNode* root, vector<int> &ans) {
    if(root == nullptr)
        return;
    inorderTraversalUtil(root->left, ans);
    ans.push_back(root->val);
    inorderTraversalUtil(root->right, ans);
}
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    inorderTraversalUtil(A, ans);
    return ans;
}

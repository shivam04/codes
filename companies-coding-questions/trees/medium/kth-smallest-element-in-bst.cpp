/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* ansa(TreeNode* root, int &k) {
    if(root==NULL)
        return root;
    TreeNode* left = ansa(root->left, k);
    if (left != NULL)
        return left;
    k--;
    if(k==0)
        return root;
    return ansa(root->right, k);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    TreeNode* ans = ansa(A, B);
    if(ans==NULL)
        return -1;
    return ans->val;
}

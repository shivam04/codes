/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* A, int B) {
    if(A==NULL)
        return 0;
    B -= A->val;

    bool ans = 0;
    if(B==0 and A->left==NULL and A->right==NULL)
        return 1;

    ans = ans or hasPathSum(A->left,B) or hasPathSum(A->right, B);
    return ans;
}

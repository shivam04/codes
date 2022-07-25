/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solveUtil(TreeNode* A, int &ans) {
    if(A==NULL)
        return 0;
    if(A->left == NULL and A->right==NULL)
        return A->val;
    int ls = solveUtil(A->left, ans);
    int rs = solveUtil(A->right, ans);

    if(ls+rs!=A->val)
        ans = 0;
    return ls+rs+A->val;
}
int Solution::solve(TreeNode* A) {
    int ans = 1;
    solveUtil(A, ans);
    return ans;
}

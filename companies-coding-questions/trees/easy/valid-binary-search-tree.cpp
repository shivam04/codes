/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int isValidBSTUtil(TreeNode *A, TreeNode **prev) {
    if(A==NULL)
        return 1;
    if(!isValidBSTUtil(A->left, prev))
        return 0;
    if(*prev != NULL and A->val <= (*prev)->val)
        return 0;
    *prev = A;
    return isValidBSTUtil(A->right, prev);

}
int Solution::isValidBST(TreeNode* A) {
    TreeNode* prev = NULL;
    return isValidBSTUtil(A, &prev);
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    if (A == NULL || A->left == NULL && A->right == NULL)
        return A;
    if(A->left != NULL) {
        flatten(A->left);
        TreeNode* tR = A->right;
        A->right = A->left;
        A->left = NULL;
        TreeNode* t = A->right;
        while (t->right != NULL) 
            t = t->right;
        t->right = tR;
    }
    flatten(A->right);
    return A;
}

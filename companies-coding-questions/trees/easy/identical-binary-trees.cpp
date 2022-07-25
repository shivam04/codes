/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A==NULL and B==NULL)
        return 1;
    else if((A==NULL and B!=NULL) or (A!=NULL and B==NULL))
        return 0;
    return (A->val==B->val and isSameTree(A->left, B->left) and isSameTree(A->right, B->right));
}

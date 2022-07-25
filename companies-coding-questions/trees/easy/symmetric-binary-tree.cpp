/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int isMirror(TreeNode* r1, TreeNode* r2) {
    if(r1==NULL and r2==NULL)
        return 1;
    if(r1 and r2 and r1->val == r2->val) {
        return isMirror(r1->left, r2->right) and isMirror(r1->right,r2->left);
    }
    return 0;
}
int Solution::isSymmetric(TreeNode* A) {
    return isMirror(A,A);
}

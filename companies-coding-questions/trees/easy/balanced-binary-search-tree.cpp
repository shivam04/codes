/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int isBalancedUtil(TreeNode *root, int &height) {
    int lh = 0, rh = 0;
    int l = 0, r = 0;
    if (root == NULL) {
        height = 0;
        return 1;
    }
    l = isBalancedUtil(root->left, lh);
    r = isBalancedUtil(root->right, rh);

    height = max(lh, rh) + 1;

    if(abs(rh-lh)>=2)
        return 0;
    return l&r;

}
int Solution::isBalanced(TreeNode* A) {
    int h = 0;
    return isBalancedUtil(A, h);
}

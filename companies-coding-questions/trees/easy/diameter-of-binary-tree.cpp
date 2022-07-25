/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int diameter(TreeNode* root, int &height) {
    int lh = 0, rh = 0;
    int ldiameter = 0, rdiameter = 0;
    if(root==NULL) {
        height = 0;
        return 0;
    }

    ldiameter = diameter(root->left, lh);
    rdiameter = diameter(root->right, rh);
    height = max(lh,rh) + 1;
    return max(lh + rh , max(ldiameter, rdiameter));
}
int Solution::solve(TreeNode* A) {
    if(A==NULL)
        return 0;
    int height = 0;
    return diameter(A, height);
}
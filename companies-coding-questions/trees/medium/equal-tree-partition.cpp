//O(n^2)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int sumNodes(TreeNode *root) {
    if(root == NULL)
        return 0;
    return sumNodes(root->left) + sumNodes(root->right) + root->val;
}
int check(TreeNode* root, int n) {
    if(root == NULL)
        return 0;
    if(sumNodes(root) == n-sumNodes(root)) 
        return 1;
    return check(root->left, n) ||
           check(root->right, n);
}
int Solution::solve(TreeNode* A) {
    int s = sumNodes(A);
    return check(A, s);
}



//O(n)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int sumNodes(TreeNode *root) {
    if(root == NULL)
        return 0;
    return sumNodes(root->left) + sumNodes(root->right) + root->val;
}
int check(TreeNode* root, int n, int &res) {
    if(root == NULL)
        return 0;
    int c = check(root->left, n, res) + root->val +
            check(root->right, n, res);
    if(c==n-c)
        res = 1;
    return c;
}
int Solution::solve(TreeNode* A) {
    int s = sumNodes(A);
    int ans = 0;
    check(A, s, ans);
    return ans;
}

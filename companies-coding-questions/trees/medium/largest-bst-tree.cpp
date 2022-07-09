/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Info
{
    int sz; // Size of subtree
    int max; // Min value in subtree
    int min; // Max value in subtree
    int ans; // Size of largest BST which
    // is subtree of current node
    bool isBST; // If subtree is BST
};
Info largestBSTBT(TreeNode* root) {
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};

    if (root->left == NULL && root->right == NULL)
        return {1, root->val, root->val, 1, true};

    Info l = largestBSTBT(root->left);
    Info r = largestBSTBT(root->right);

    Info ret;
    ret.sz = (1 + l.sz + r.sz);
    if (l.isBST && r.isBST && l.max < root->val && r.min > root->val) {
        ret.min = min(l.min, min(r.min, root->val));
        ret.max = max(r.max, max(l.max, root->val));
        ret.ans = l.ans + r.ans + 1;
        ret.isBST = true;
 
        return ret;
    }

    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;
    return ret;
}
int Solution::solve(TreeNode* A) {
    return largestBSTBT(A).ans;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* findLca(TreeNode* root, int n1, int n2, bool &v1, bool &v2) {
    if(root==NULL)
        return NULL;
    if(root->val == n1) {
        v1 = true;
        return root;
    }

    if(root->val == n2) {
        v2 = true;
        return root;
    }

    TreeNode* l = findLca(root->left, n1, n2, v1, v2);
    TreeNode* r = findLca(root->right, n1, n2, v1, v2);

    if(l and r) return root;
    return (l!=NULL) ? l : r;
}
int distance(TreeNode* par, int n, int dis) {
    if(par->val==n) {
        return dis;
    }
    if(n<par->val) {
        return distance(par->left, n, dis+1);
    }
    return distance(par->right, n, dis+1);
}
int Solution::solve(TreeNode* A, int B, int C) {
    bool v1 = false, v2 = false;
    TreeNode* lca = findLca(A, B, C, v1, v2);
    return (distance(lca,B,0) + distance(lca,C,0));
}

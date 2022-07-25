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
bool find(TreeNode *root, int k) {
    if (root == NULL)
        return false;
    if (root->val == k || find(root->left, k) ||  find(root->right, k)) {
        return true;
    }
    return false;
}
int Solution::lca(TreeNode* A, int B, int C) {
    bool v1 = false, v2 = false;
    TreeNode* lca = findLca(A, B, C, v1, v2);
    if((v1 and v2) or (v1 and find(lca, C)) or (v2 and find(lca, B))) {
        return lca->val;
    }
    return -1;
}

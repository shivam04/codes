/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void countUtil(TreeNode* root, int s, int e, int &count) {
    if(root==NULL)
        return;
    if(root->val<=e and root->val>=s) {
        count++;
        countUtil(root->left, s, e, count);
        countUtil(root->right, s, e, count);
    }


    else if(root->val < s) {
        countUtil(root->right, s, e, count);
    }
    else {
        countUtil(root->left, s, e, count);
    }
        
}
int Solution::solve(TreeNode* A, int B, int C) {
    int count = 0;
    countUtil(A, B, C, count);
    return count;
}

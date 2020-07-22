/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void transform(TreeNode* root, int &sum) {
        if (root == NULL)  return;
        transform(root->right, sum);
        sum += root->val;
        root->val = sum;
        transform(root->left, sum);
    }
    void printNode(TreeNode* root) {
        if(!root)
            return;
        printNode(root->left);
        cout<<root->val<<"\n";
        printNode(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        transform(root, sum);
        return root;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int lheight(TreeNode* root) {
        int c = 0;
        while(root!=NULL) {
            c++;
            root = root->left;
        }
        return c;
    }
    
    int rheight(TreeNode* root) {
        int c = 0;
        while(root!=NULL) {
            c++;
            root = root->right;
        }
        return c;
    }
    int countNodes(TreeNode* root) {
        int lh = lheight(root);
        int rh = rheight(root);
        if(lh==rh) {
            return (1<<lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
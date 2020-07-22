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
    void inorder(TreeNode *root, vector<int> &k) {
        if(!root)
            return;
        inorder(root->left, k);
        k.push_back(root->val);
        inorder(root->right, k);
    }
    void inorderInsert(TreeNode *root, vector<int> &k, int &st) {
        if(!root) 
            return;
        inorderInsert(root->left, k, st);
        while(st < k.size() && k[st] < root->val)  {
            st++;
        }
        k.insert(k.begin() + st, root->val);
        inorderInsert(root->right, k, st);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> k;
        inorder(root1, k);
        int start= 0;
        inorderInsert(root2, k, start);
        return k;
    }
};
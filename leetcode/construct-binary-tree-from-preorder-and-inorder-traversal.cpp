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
    int idx = 0;
    TreeNode* buildTreeUtil(vector<int>& preorder, vector<int>& inorder,int iS, int iE,     unordered_map<int, int> &mp) {
        if(iS > iE)
            return NULL;
        TreeNode* node = new TreeNode(preorder[idx]);
        int i = mp[preorder[idx++]];
        if (iS == iE) 
            return node; 
        node->left = buildTreeUtil(preorder, inorder, iS, i-1, mp);
        node->right = buildTreeUtil(preorder, inorder, i+1, iE, mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp; 
        int len = inorder.size();
        for (int i = 0; i < len; i++) 
            mp[inorder[i]] = i; 
        idx = 0;
        return buildTreeUtil(preorder, inorder, 0, len-1, mp);
    }
};
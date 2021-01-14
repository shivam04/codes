class Solution {
public:
    int max(int a, int b){
        return a>b?a:b;
    }
    int goodNodesUtil(TreeNode* root, int mini) {
        if(!root)
            return 0;
        int l = goodNodesUtil(root->left, max(mini,root->val));
        int r = goodNodesUtil(root->right, max(mini,root->val));
        return (l+r+(root->val>=mini));
    }
    int goodNodes(TreeNode* root) {
        return goodNodesUtil(root, INT_MIN);
    }
};
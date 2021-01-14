class Solution {
public:
    map<TreeNode*, int> depth;
    TreeNode* answer(TreeNode* root) {
        int left = getDepth(root->left), right = getDepth(root->right);
        if (left == right) return root;
        return (left > right) ? subtreeWithAllDeepest(root->left) : subtreeWithAllDeepest(root->right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return nullptr;
        depth.clear();
        return answer(root);
    }
    int getDepth(TreeNode* node) {
        if (!node) return 0;
        if(depth.find(node) != depth.end())
            return depth[node];
        return (depth[node] = 1 + max(getDepth(node->left), getDepth(node->right)));
    }
};
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
class FindElements {
public:
    set <int> a;
    void ge(TreeNode* root, int x) {
        if(!root)
            return;
        root->val = x;
        a.insert(x);
        ge(root->left, 2*x+1);
        ge(root->right, 2*x+2);
    }
    FindElements(TreeNode* root) {
        if(!root)
            return;
        a.clear();
        ge(root, 0);
    }
    
    bool find(int target) {
        return (a.find(target) != a.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
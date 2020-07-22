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
   void dfs(TreeNode* root,int rootVal=-1){
      if(!root)return;
      root->val = rootVal == -1?0:rootVal;
      a.insert(root->val);
      dfs(root->left,2*root->val + 1);
      dfs(root->right, 2*root->val + 2);
   }
   FindElements(TreeNode* root) {
      dfs(root);
   }
   bool find(int t) {
      return a.find(t)!=a.end();
   }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
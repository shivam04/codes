/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;

    queue<TreeNode*> q;

    q.push(A);

    ans.push_back(A->val);
    while(!q.empty()) {
        auto r = q.front();
        q.pop();

        if(r->left) {
            ans.push_back(r->left->val);
            q.push(r->left);
        } else {
            ans.push_back(-1);
        }

        if(r->right) {
            ans.push_back(r->right->val);
            q.push(r->right);
        } else {
            ans.push_back(-1);
        }
    }
    return ans;
}

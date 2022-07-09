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
        queue<TreeNode*> tq;
        int laste = -1;
        while(!q.empty()) {
            auto t = q.front();
            q.pop();

            if(t->left) {
                laste = (laste == -1) ? t->left->val : laste;
                tq.push(t->left);
            }

            if(t->right) {
                laste = (laste == -1) ? t->right->val : laste;
                tq.push(t->right);
            }
        }
        swap(tq, q);
        if(laste>=0)
            ans.push_back(laste);
    }
    return ans;
}

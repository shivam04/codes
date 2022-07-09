/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<TreeNode*> tq,q;
    q.push(A);
    vector<vector<int>> ans;
    while(!q.empty()) {
        int sz = q.size();
        vector<int> p;
        while(!q.empty()) {
            TreeNode* r = q.front();
            q.pop();
            p.push_back(r->val);
            if(r->left) {
                tq.push(r->left);
            }

            if(r->right) {
                tq.push(r->right);
            }
        }
        ans.push_back(p);
        swap(q,tq);
    }
    return ans;
}

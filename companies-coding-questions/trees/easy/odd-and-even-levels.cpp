/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A) {
    int lvl = 0;

    queue<TreeNode*> q;

    q.push(A);

    vector<long> sum(2);
    sum[0] = 0;
    sum[1] = 0;

    while(!q.empty()) {
        queue<TreeNode*> tq;
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            sum[lvl] = (sum[lvl] + (long)temp->val);
            if(temp->left)
                tq.push(temp->left);
            if(temp->right)
                tq.push(temp->right);
        }
        swap(tq, q);
        lvl = 1 - lvl;
    }
    return (sum[0] - sum[1]);

}

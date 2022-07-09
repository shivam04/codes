/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    int lvl = 0;
    vector<vector<int> > ans;

    queue<TreeNode*> q;

    q.push(A);

    while(!q.empty()) {
        queue<TreeNode*> tq;
        vector<int> vv;
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            vv.push_back(temp->val);
            if(temp->left)
                tq.push(temp->left);
            if(temp->right)
                tq.push(temp->right);
        }
        if(lvl==1)
            reverse(vv.begin(), vv.end());
        ans.push_back(vv);
        lvl = 1 - lvl;
        swap(q,tq);
    }
    return ans;
}

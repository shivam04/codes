/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    unordered_map<int, vector<int>> mp;
    queue<pair<TreeNode*, int>> q;
    int minv = 0, maxv = 0;

    q.push({A,0});

    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        TreeNode* node = t.first;
        minv = min(minv, t.second);
        maxv = max(maxv, t.second);
        mp[t.second].push_back(node->val);

        if(node->left) {
            q.push({node->left, t.second-1});
        }
        if(node->right) {
            q.push({node->right, t.second+1});
        }
    }
    vector<vector<int>> ans;
    for(int i=minv; i<=maxv;i++) {
        ans.push_back(mp[i]);
    }
    return ans;
}

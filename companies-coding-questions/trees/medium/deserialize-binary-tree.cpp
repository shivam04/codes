/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(vector<int> &A) {
    queue<TreeNode*> q;
    
    TreeNode* root = new TreeNode(A[0]);
    q.push(root);

    int lI = 0;
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        int l = lI+1;
        int r = lI+2;
        if(l<A.size() and A[l]!=-1) {
            curr->left = new TreeNode(A[l]);
            q.push(curr->left);
        }
        if(r< A.size() and A[r]!=-1) {
            curr->right = new TreeNode(A[r]);
            q.push(curr->right);
        }
        lI = r;
    }
    return root;
}

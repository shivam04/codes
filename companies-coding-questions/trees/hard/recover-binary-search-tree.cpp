/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* root, vector<int> &ino) {
    if(!root)
        return;
    inorder(root->left, ino);
    ino.push_back(root->val);
    inorder(root->right, ino);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ino;
    inorder(A, ino);
    vector<int> ans;
    int n = ino.size();
    for(int i=0;i<n-1;i++) {
        if(ino[i] > ino[i+1]) {
            ans.push_back(ino[i]);
            break;
        }
    }

    for(int i=n-1;i>=1;i--) {
        if(ino[i] < ino[i-1]) {
            ans.push_back(ino[i]);
            break;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

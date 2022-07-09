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
    if(root==NULL)
        return;
    inorder(root->left, ino);
    ino.push_back(root->val);
    inorder(root->right, ino);
}
int Solution::t2Sum(TreeNode* A, int B) {
    vector<int> ino;
    inorder(A, ino);
    int l = 0;
    int h = ino.size() - 1;
    while(l<h) {
        if(ino[l]+ino[h] == B) 
            return 1;
        else if(ino[l] + ino[h] < B) 
            l++;
        else
            h--;
    }
    return 0;
}

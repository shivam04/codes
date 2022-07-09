/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int search(vector<int> &arr, int ele, int s, int e) {
    for(int i=s;i<=e;i++) {
        if(arr[i]==ele) {
            return i;
        }
    }
    return -1;
}
TreeNode* buildTreeUtil(vector<int> &ino, vector<int> &pre, int inS, int inE, int &preI) {
    if(inS > inE)
        return nullptr;
    TreeNode* root = new TreeNode(pre[preI]);
    preI++;
    if(inS==inE)
        return root;
    int iIndex = search(ino, root->val, inS, inE);
    root->left = buildTreeUtil(ino, pre, inS, iIndex-1, preI);
    root->right = buildTreeUtil(ino, pre, iIndex+1, inE, preI);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int preI = 0;
    return buildTreeUtil(B, A, 0, B.size()-1, preI);
}

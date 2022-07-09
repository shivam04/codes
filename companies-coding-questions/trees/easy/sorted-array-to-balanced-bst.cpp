/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* sortedArrayToBSTUtil(const vector<int> &A, int s, int e) {
    if(s>e)
        return NULL;
    if(s==e)
        return new TreeNode(A[s]);
    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(A[mid]);
    root->left = sortedArrayToBSTUtil(A, s, mid-1);
    root->right = sortedArrayToBSTUtil(A, mid+1, e);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return sortedArrayToBSTUtil(A, 0 ,A.size()-1);
}

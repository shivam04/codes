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
TreeNode* buildTreeUtil(vector<int> &ino, vector<int> &post, int inS, int inE, int &postI) {
    if(inS > inE)
        return nullptr;
    TreeNode* root = new TreeNode(post[postI]);
    postI--;
    if(inS==inE)
        return root;
    int iIndex = search(ino, root->val, inS, inE);
    root->right = buildTreeUtil(ino, post, iIndex+1, inE, postI);
    root->left = buildTreeUtil(ino, post, inS, iIndex-1, postI);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int postI = A.size()-1;
    return buildTreeUtil(A, B, 0, A.size()-1, postI);
}

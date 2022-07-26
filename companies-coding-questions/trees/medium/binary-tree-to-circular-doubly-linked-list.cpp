/*
Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
void convert(TreeNode* curr, TreeNode* &head, TreeNode* &prev) {
    if(curr==nullptr)
        return;
    convert(curr->left,head,prev);
    if(prev != nullptr) {
        prev->right = curr;
        curr->left = prev;
    } else {
        head = curr;
    }
    prev = curr;
    convert(curr->right, head, prev);
}
TreeNode* solve(TreeNode *A){
    TreeNode* head = nullptr, *prev = nullptr;
    convert(A,head,prev);
    return head;
}

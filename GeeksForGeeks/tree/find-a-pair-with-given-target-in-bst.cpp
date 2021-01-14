void inorderTrav(struct Node *root, vector<int> &inorder) {
    if(root == NULL)
        return;
    inorderTrav(root->left, inorder);
    inorder.push_back(root->data);
    inorderTrav(root->right, inorder);
}
int isPairPresent(struct Node *root, int target) {
    vector<int> inorder;
    inorderTrav(root, inorder);
    int i=0;
    int j=inorder.size()-1;
    while(i<j) {
        if(inorder[i] + inorder[j] == target) {
            return 1;
        } else if(inorder[i] + inorder[j] < target) {
            i++;
        } else {
            j--;
        }
    }
    return 0;
}
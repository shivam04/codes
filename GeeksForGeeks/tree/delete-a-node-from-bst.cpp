Node *deleteNode(Node *root,  int X) {
    if(root == NULL)
        return root;
    if(root->data > X) {
        root->left = deleteNode(root->left, X);
        return root;
    } else if(root->data < X){
        root->right = deleteNode(root->right, X);
        return root;
    }
    
    if(root->left == NULL) {
        Node *temp = root->right;
        delete root;
        return temp;
    } else if(root->right == NULL) {
        Node *temp = root->left;
        delete root;
        return temp;
    } else {
        Node* succParent = root;
        Node* succ = root->right;
        while(succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        if(succParent != root) {
            succParent->left = succ->right;
        } else {
            succParent->right = succ->right;
        }
        root->data = succ->data;
        delete succ;
        return root;
    }
    
}
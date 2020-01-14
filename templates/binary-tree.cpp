class BinaryTree {
public:
    i32 data;
    BinaryTree *left, *right;

public:
	BinaryTree(){
		data = 0;
		left = NULL;
		right = NULL;
	}
    BinaryTree( i32 node_data ) {
        data = node_data;
        left = NULL;
        right = NULL;
    }
};
BinaryTree *insert(BinaryTree *root, i32 data){
    if(root==NULL){
        BinaryTree *node = new BinaryTree(data);
        return node;
    }
    if(root->data>data){
        root->left = insert(root->left,data);
    }else if(root->data < data){
        root->right = insert(root->right,data);
    }
    return root;
}

void preorder(BinaryTree *root)
{
    if(root)
    {
        wi(root->data); wln(" ");   //Printf root->data
        preorder(root->left);    //Go to left subtree
        preorder(root->right);     //Go to right subtree
    }
}

void postorder(struct node*root)
{
    if(root)
    {
        postorder(root->left);    //Go to left sub tree
        postorder(root->right);     //Go to right sub tree
        wi(root->data); wln(" ");   //Printf root->data
    }
}

void inorder(BinaryTree *root)
{
    if(root)
    {
        inorder(root->left);    //Go to left subtree
        wi(root->data); wln(" ");   //Printf root->data
        inorder(root->right);     //Go to right subtree
    }
}
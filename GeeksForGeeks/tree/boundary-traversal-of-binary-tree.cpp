/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
void printleaves(Node *root){
    if(root){
        printleaves(root->left);
        if(root->right==NULL and root->left==NULL)
        cout<<root->data<<" ";
        printleaves(root->right);
    }
}
void printboundaryleft(Node *root){
    if(root){
        if(root->left){
            cout<<root->data<<" ";
            printboundaryleft(root->left);
        }else if(root->right){
            cout<<root->data<<" ";
            printboundaryleft(root->right);
        }
    }
}
void printboundaryright(Node *root){
    if(root){
        if(root->right){
            printboundaryright(root->right);
            cout<<root->data<<" ";
        }else if(root->left){
            printboundaryright(root->left);
            cout<<root->data<<" ";
            
        }
    }
}
void printBoundary(Node *root)
{
    if(root){
        cout<<root->data<<" ";
        printboundaryleft(root->left);
        printleaves(root->left);
        printleaves(root->right);
        printboundaryright(root->right);
    }
}
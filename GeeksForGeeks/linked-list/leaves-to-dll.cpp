/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/
Node *convertToDLL(Node *root,Node **head_ref)
{
    if(root==NULL)
    return root;
    if(root->left==NULL and root->right==NULL){
        root->right = (*head_ref);
        if(*head_ref!=NULL){
            (*head_ref)->left = root;
        }
        *head_ref=root;
        return NULL;
    }
    root->right =  convertToDLL(root->right,head_ref);
    root->left =  convertToDLL(root->left,head_ref);
    return root;
}
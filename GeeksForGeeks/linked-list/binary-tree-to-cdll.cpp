/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows:
struct Node
{
    struct Node *left, *right;
    int data;
};*/
Node *concatenate(Node *leftList, Node *rightList)
{
    if (leftList == NULL)
        return rightList;
    if (rightList == NULL)
        return leftList;
    Node *leftLast = leftList->left;
    Node *rightLast = rightList->left;
    leftLast->right = rightList;
    rightList->left = leftLast;
    leftList->left = rightLast;
    rightLast->right = leftList;
    return leftList;
}
Node *bTreeToCList(Node *root)
{
    if(root==NULL)
    return root;
    Node *left = bTreeToCList(root->left);
    Node *right = bTreeToCList(root->right);
    root->left = root->right = root;
    return concatenate(concatenate(left, root), right);
}
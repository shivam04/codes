#include <bits/stdc++.h>
using namespace std;
class BinaryTree {
public:
    int data;
    BinaryTree *left, *right;

public:
	BinaryTree(){
		data = 0;
		left = NULL;
		right = NULL;
	}
    BinaryTree( int node_data ) {
        data = node_data;
        left = NULL;
        right = NULL;
    }
};
BinaryTree *insert(BinaryTree *root, int data){
    if(root==NULL){
        BinaryTree *node = new BinaryTree(data);
        return node;
    }
    if(root->data>=data){
        root->left = insert(root->left,data);
    }else if(root->data < data){
        root->right = insert(root->right,data);
    }
    return root;
}
int height(BinaryTree *root){
    int p=0,q=0;
    if(root==NULL)
    return 0;
    p = height(root->left);
    q = height(root->right);
    if(p>q)
        return p+1;
    else
        return q+1;
}


int main()
{
    int n;
    cin>>n;
    int a;
    int i;
    BinaryTree *root = NULL;
    for(i=0;i<n;i++){
        cin>>a;    
        root = insert(root,a);
    }
    cout<<height(root);
    return 0;
}

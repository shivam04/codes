#include <bits/stdc++.h>
using namespace std;
int maxi = -1;
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
    if(root->data>data){
        root->left = insert(root->left,data);
    }else if(root->data < data){
        root->right = insert(root->right,data);
    }
    return root;
}
/*void preorder(BinaryTree *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}*/
int maxBST(BinaryTree *root, int a){
    
        if(root->data == a)
        {
           return max(maxi,a);
        }
        else if(root->data>a){
            maxi = max(root->data,maxi);
            return maxBST(root->left,a);
        }else{
            maxi = max(root->data,maxi);
            return maxBST(root->right,a);
        }
    
}
int findMax(int x, int y,BinaryTree *root)
{
	BinaryTree *p = root;
	while((x < p->data and y < p->data) or (x > p->data and y > p->data))
	{
		if(x < p->data and y < p->data)
			p = p->left;
		else if(x > p->data and y > p->data)
			p = p->right;
	}
	return max(maxBST(p, x), maxBST(p, y));
}
int main(){
    int n;
    int i,a;
    cin>>n;
    BinaryTree *root = NULL;
    for(i=0;i<n;i++){
        cin>>a;    
        root = insert(root,a);
    }
    //preorder(root);
   // cout<<"\n";
    int x,y;
    cin>>x>>y;
    int p,q;
    
    //if(root==NULL)cout<<"YO\n";
  //  p = maxBST(root,x);
   // cout<<p<<"\n";
   // maxi = -1;
   // q = maxBST(root,y);
   // cout<<q<<"\n";
    cout<<findMax(x,y,root)<<"\n";
    return 0;
}
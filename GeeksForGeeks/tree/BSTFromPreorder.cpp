#include <bits/stdc++.h>
using namespace std;

class Node  {  
    public: 
	    int data;  
	    Node *left;  
	    Node *right;  
};  
  
Node* newNode (int data)  {  
    Node* temp = new Node(); 
    temp->data = data;  
    temp->left = temp->right = NULL;  
    return temp;  
} 

Node *createBSTUtil(int arr[], int *i, int data, int mini, int maxi, int n) {
	if(*i >= n)
		return NULL;
	Node* root = NULL;
	if( data > mini && data < maxi ) {
		root = newNode(data);
		*i = *i + 1;
		if(*i < n) {
			root->left = createBSTUtil(arr,i,arr[*i],mini,data,n);
			root->right = createBSTUtil(arr,i,arr[*i],data,maxi,n);
		}
	}
	return root;
}

Node *createBST(int arr[], int n) {
	int preIndex = 0;
	return createBSTUtil(arr,&preIndex,arr[0],INT_MIN,INT_MAX,n);
}
void printInorder (Node* node)  {  
    if (node == NULL)  
        return;  
    printInorder(node->left);  
    cout << node->data << " ";  
    printInorder(node->right);  
}

int main() {
	int pre[] = {10, 5, 1, 7, 40, 50};  
    int size = sizeof( pre ) / sizeof( pre[0] );
    Node *root = createBST(pre, size);
    printInorder(root);  
	return 0;
}
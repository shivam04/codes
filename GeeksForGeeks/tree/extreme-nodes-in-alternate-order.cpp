// { Driver Code Starts
/* C++ program to print nodes of extreme corners
of each level in alternate order */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

/* Function to print nodes of extreme corners
of each level in alternate order */
void printExtremeNodes(Node* root);


/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
   printExtremeNodes(root);
   cout<<endl;

  }
    return 0;
}

// } Driver Code Ends
/*
 A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

/* Function to print nodes of extreme corners
of each level in alternate order */
void printExtremeNodes(Node* root) {
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    bool flag = false; 
    while(!q.empty()) {
        int n = q.size();
        int nodecount = n;
        while(n--) {
            Node* curr = q.front();
            if (curr->left) 
                q.push(curr->left); 
            if(curr->right)
                q.push(curr->right);
            q.pop();
            
            if(flag and n==nodecount-1)
                cout<<curr->data<<" ";
            else if(!flag and n==0)
                cout<<curr->data<<" ";
        }
        flag = !flag;
    }
}

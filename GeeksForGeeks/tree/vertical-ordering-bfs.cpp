// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};



void verticalOrder(Node *root);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     verticalOrder(root);
     cout << endl;
  }
  return 0;
}

// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
 
void verticalOrder(Node *root) {
    map<int, vector<int>> mp;
    int l = 0;
    queue<pair<Node *, int>> q;
    q.push({root,l});
    while(!q.empty()) {
        pair<Node *,int> temp = q.front(); 
        q.pop();
        l = temp.second;
        Node *node = temp.first;
        mp[l].push_back(node->data);
        if(node->left!=NULL)
            q.push({node->left, l-1});
        if(node->right!=NULL)
            q.push({node->right, l+1});
    }
    for(auto it = mp.begin(); it!=mp.end();++it) {
        for(int i=0;i<it->second.size();i++) {
            cout<<it->second[i]<<" ";
        }
    }
}


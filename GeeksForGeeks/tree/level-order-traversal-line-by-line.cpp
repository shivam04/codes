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
//You are required to complete this method
void levelOrder(Node* node)
{
  int k=0,c = 1;
  queue<Node*> q;
  unordered_map<Node*,int> visit;
  visit[node]=1;
  q.push(node);
  while(!q.empty()){
      Node* n = q.front();
      q.pop();
      c--;
      cout<<n->data<<" ";
      if(c==0)
      cout<<"$ ";
      if(n->left and visit[n->left]==0){
          visit[n->left]=1;
          q.push(n->left);
          k++;
      }
      if(n->right and visit[n->right]==0){
          visit[n->right]=1;
          q.push(n->right);
          k++;
      }
      if(c==0){
        c=k;
        k=0;
      }
  }
}

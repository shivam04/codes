map<int, vector<int> > mp;
void diagonalPrintUtil(Node* root, int d) {
    if (!root) 
        return; 
    mp[d].push_back(root->data); 
    diagonalPrintUtil(root->left, d + 1); 
    diagonalPrintUtil(root->right, d);
}
void diagonalPrint(Node *root)
{
   mp.clear();
   diagonalPrintUtil(root, 0);
   for(auto it = mp.begin(); it!=mp.end();++it) {
       for(int i=0;i<it->second.size();i++) {
           cout<<it->second[i]<<" ";
       }
       //cout<<"\n";
   }
}
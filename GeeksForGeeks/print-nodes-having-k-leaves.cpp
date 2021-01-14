int btWithKleaves(Node *ptr, int k, vector<int> &ans){
    if(!ptr) {
        return 0;
    }
    if(!ptr->left and !ptr->right)
        return 1;
    int l = btWithKleaves(ptr->left, k ,ans);
    int r = btWithKleaves(ptr->right, k ,ans);
    if(l+r==k) {
        ans.push_back(ptr->data);
    }
    return l+r;
}
vector<int> btWithKleaves(Node *ptr, int k) { 
    vector<int> ans;
    btWithKleaves(ptr,k,ans);
    if(ans.size()==0)
        ans.push_back(-1);
    return ans;
}
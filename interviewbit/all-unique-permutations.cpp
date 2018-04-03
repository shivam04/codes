vector<vector<int> > v;
map<vector<int>,bool>mp;
void ans(vector<int> A,int s){
    if(s==A.size()-1){
        if(mp[A]==false){
            mp[A] = true;
            v.push_back(A);
        }
        return ;
    }
    for(int i=s;i<A.size();i++){
        swap(A[s],A[i]);
        ans(A,s+1);
        swap(A[s],A[i]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    v.clear();
    mp.clear();
    ans(A,0);
    return v;
}

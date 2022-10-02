void ans(set<vector<int> > &k,vector<int> A,int s) {
    if(s==A.size()-1){
        k.insert(A);
        return ;
    }
    for(int i=s;i<A.size();i++){
        swap(A[s],A[i]);
        ans(k,A,s+1);
        swap(A[s],A[i]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    set<vector<int> > k;
    vector<int> p;
    ans(k,A,0);
    vector<vector<int> > ans(k.begin(), k.end());
    return ans;
}
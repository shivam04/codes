void ans(vector<vector<int> > &k,vector<int> A,int s){
    if(s==A.size()-1){
            k.push_back(A);
            return ;
    }
    for(int i=s;i<A.size();i++){
        swap(A[s],A[i]);
        ans(k,A,s+1);
        swap(A[s],A[i]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > k;
    vector<int> p;
    ans(k,A,0);
    return k;
}

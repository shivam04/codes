void ans(set<vector<int> > &k,vector<int> p,int s,int n,vector<int> &A){
    for(int i=s;i<n;i++){
        p.push_back(A[i]);
        k.insert(p);
        ans(k,p,i+1,n,A);
        p.pop_back();
        
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(),A.end());
    set<vector<int> > k;
    int n = A.size();
    vector<int> p;
    k.insert(p);
    ans(k,p,0,n,A);
    vector<vector<int> > anss(k.begin(), k.end());
    return anss;
}

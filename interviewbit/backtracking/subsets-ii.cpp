void ans(vector<vector<int> > &k,vector<int> p,int s,int n,vector<int> &A){
    for(int i=s;i<n;i++){
        p.push_back(A[i]);
        if(find(k.begin(),k.end(),p)==k.end())
        k.push_back(p);
        ans(k,p,i+1,n,A);
        p.pop_back();
    }
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int> > k;
    int n = A.size();
    vector<int> p;
    k.push_back(p);
    ans(k,p,0,n,A);
    k.erase(unique(k.begin(), k.end()), k.end());
    return k;
}

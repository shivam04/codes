void ans(vector<vector<int> > &k,vector<int> p,int s,int A ,int B){
    if(B==0){
        k.push_back(p);
        return ;
    }
    for(int i=s;i<=A;i++){
        p.push_back(i);
        ans(k,p,i+1,A,B-1);    
        p.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int> > k;
    vector<int> p;
    ans(k,p,1,A,B);
    return k;
}
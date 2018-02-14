vector<int> Solution::findPerm(const string A, int B) {
    int i = B;
    int d = 1;
    vector<int> v;
    int x;
    for(x=0;x<A.size();x++){
        if(A[x]=='I'){
            v.push_back(d++);
        }else{
            v.push_back(i--);
        }
    }
    v.push_back(d);
    return v;
}

bool check(vector<string>a,string s,int st,int e){
    int i;
    int n = a.size();
    for(i=0;i<n;i++){
        for(int j=st;j<=e;j++){
            if(a[i][j]!=s[j])
                return false;
        }
    }
    return true;
}
string Solution::longestCommonPrefix(vector<string> &A) {
    int minilen = INT_MAX;
    for(int i=0;i<A.size();i++){
        int p =A[i].length();
        minilen = min(minilen,p);
    }
    int l = 0;
    int r = minilen;
    string pre;
    while(l<r){
        int mid= (l+r)/2;
        if(check(A,A[0],l,mid)){
            pre = pre+A[0].substr(l,mid-l+1);
            l=mid+1;   
        }else{
            r=mid;
        }
    }
    return pre;
}

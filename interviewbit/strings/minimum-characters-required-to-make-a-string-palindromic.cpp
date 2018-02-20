int Solution::solve(string A) {
    string k = A;
    reverse(k.begin(), k.end());
    string c = A+'$'+k;
    
    int len = 0;
    
    int i = 1;
    int M = c.length();
    vector<int> lps(M);
    lps[0] = 0;
    while(i<M){
        if(c[i]==c[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0)
                len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    //cout<<lps.size()<<"\n";
    return (A.length()-lps.back());
}

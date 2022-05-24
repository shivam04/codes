int Solution::findRank(string A) {
    int l=A.length();
    long ans=1,mod=1000003;
    long rank[130]={0},fact[130]={0};
    fact[0]=fact[1]=1;
    for(int i=2;i<=120;i++) {
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
    }
    string str=A;
    sort(begin(str),end(str));
    for(int i=0;i<l;i++)
        rank[str[i]-'A']=i;
    for(int i=0;i<l;i++) {
        ans+=(rank[A[i]-'A'])*fact[l-1-i];
        ans%=mod;
        int j=A[i]-'A'+1;
        for(;j<126;j++)rank[j]--;
    }
    return ans;
}

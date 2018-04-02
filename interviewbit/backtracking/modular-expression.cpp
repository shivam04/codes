int Solution::Mod(int A, int B, int C) {
    if(A==0)
    return A;
    A = A%C;
    long long ans = 1;
    while(B){
        if(B&1)
        ans = (ans%C*(long)A%C)%C;
        B/=2;
        A = ((long)A%C*(long)A%C)%C;
    }
   // cout<<ans<<"\n";
    if(ans<0)
    ans+=C;
    return ans;
}
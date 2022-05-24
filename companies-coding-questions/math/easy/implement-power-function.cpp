int Solution::pow(int A, int B, int C) {
    if(C==1) return 0;
    long ans=1;
    long a=A%C;
    while(B>0){
        if(B&1)
         ans=((ans)*a)%C;
        a=(a*a)%C;
        if(a<0) a+=C;
        B>>=1;
    }
    if(ans<0){
        ans=(C-abs(ans)%C);
        return ans;
    }
    return ans%C;
}

int power(int A, int B, int C) {
    if(C==1) return 0;
    long ans=1;
    long a=A%C;
    while(B>0){
        if(B&1)
         ans=((ans)*a)%C;
        a=(a%C*a%C)%C;
        B>>=1;
    }
    return ans%C;
}

int Solution::solve(int A, int B) {
    int mod = 1000000007;
    int p = mod-1;
    long y = 1;
    for(int i=1;i<=B;i++) {
        y = (y%p*i%p)%p;
    }
    return power(A,y,mod);
}

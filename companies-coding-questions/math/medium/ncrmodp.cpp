unsigned long long power(unsigned long long x, int y, int p){
    unsigned long long res = 1;
 
    x = x % p;
 
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
unsigned long long modInverse(unsigned long long n, int p){
    return power(n, p - 2, p);
}
int Solution::solve(int A, int B, int C) {
    if(A<B)
        return 0;
    if(B==0)
        return 1;
    unsigned long long fac[A + 1];
    fac[0] = 1;
    for (int i = 1; i <= A; i++) {
        fac[i] = (fac[i - 1] * i) % C;
    }
    return (fac[A] * modInverse(fac[B], C) % C
            * modInverse(fac[A - B], C) % C)
           % C;
}

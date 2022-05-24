bool isPrime(int n) {
    if (n == 1) {
    return false;
  }

  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false;
  }

  return true;
}
long modPow(int a, int b, int mod) {
    long d = a;
    long ans =1;
    while(b) {
        if(b&1) {
            ans = (ans%mod*d%mod)%mod;
        }
        d = (d%mod*d%mod)%mod;
        b/=2;
    }
    return ans;
}
int Solution::solve(vector<int> &A) {

    int mod = 1000000007;
    int c = 0;
    for(int i=0;i<A.size();i++) {
        if(isPrime(A[i])) {
            c+=1;
            //cout<<A[i]<<"\n";
        }
    }

    //cout<<p<<"\n";
    long ans = modPow(2,c,mod)-1;
    return ans;
}

int Solution::solve(vector<int> &A) {
    set<int> primeD;
    for(int n: A) {
        while(n%2==0) {
            n/=2;
            primeD.insert(2);
        }
        for(int i=3;i*i<=n;i+=2) {
            while(n%i==0) {
                n/=i;
                primeD.insert(i);
            }
        }
        if(n>2)
            primeD.insert(n);
    }
    return primeD.size();    
}

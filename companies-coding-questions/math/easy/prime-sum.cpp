vector<int> Solution::primesum(int A) {
    bool prime[A];
    memset(prime, true, sizeof(prime));
    vector<int> primes;
    for (int p = 2; p * p <=A; p++) {
        if (prime[p] == true) {
            primes.push_back(p);
            for (int i = p * p; i <= A; i += p)
                prime[i] = false;
        }
    }
    for(int i=2;i<A;i++) {
        if(prime[i] & prime[A-i]) {
            return {i,A-i};
        }
    }
    return {-1,-1};
}

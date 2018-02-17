vector<int> Solution::primesum(int A) {
    vector<bool>prime_rec;
    vector<int>prime;
    for(int i=0;i<=A;i++)
    prime_rec.push_back(true);
    for(int i=2;i<=sqrt(A);i++){
        if (prime_rec[i] == true)
        {
            for (int j=i*2; j<=A; j+=i)
                prime_rec[j] = false;
        }
    }
    for(int i=2;i<=A;i++){
       // cout<<prime[i]<<" ";
        if(prime_rec[i]){
            prime.push_back(i);
        }
    }
    if(A<=2 || A%2!=0)
    {
        vector<int>v;
        return v;
    }
    
    for(int i=0;prime[i]<=A/2;i++){
        int diff = A-prime[i];
        if (prime_rec[diff]==true)
        {
            vector<int> v;
            v.push_back(min(prime[i],diff));
            v.push_back(max(prime[i],diff));
            return v;
        }
    }
}

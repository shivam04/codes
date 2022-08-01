int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> pq;

    for(int n: B) {
        pq.push(n);
    }
    int mod = 1000000007;
    int ans = 0;

    for(int i=0;i<A;i++) {
        int b = pq.top();
        pq.pop();
        ans = (ans%mod + b%mod)%mod;

        int p = b/2;
        pq.push(p);
    }
    return ans%mod;
}

int Solution::solve(vector<int> &A, int B) {
    long ans=0;
    int mod = 1000000007;
    deque<int> s,g;
    for(int i=0;i<B;i++) {
        while(!g.empty() and A[g.back()] <= A[i]) {
            g.pop_back();
        }

        while(!s.empty() and A[s.back()] >= A[i]) {
            s.pop_back();
        }
        g.push_back(i);
        s.push_back(i);
    }
    

    for(int i=B;i<A.size();i++) {
        ans = ((ans%mod + ((long)A[s.front()]+ (long)A[g.front()])%mod) + mod)%mod;
        while(!g.empty() and g.front() <= i-B) {
            g.pop_front();
        }

        while(!s.empty() and s.front() <= i-B) {
            s.pop_front();
        }
        while(!g.empty() and A[g.back()] <= A[i]) {
            g.pop_back();
        }

        while(!s.empty() and A[s.back()] >= A[i]) {
            s.pop_back();
        }
        g.push_back(i);
        s.push_back(i);
        
    }
    ans = ((ans%mod + ((long)A[s.front()]+ (long)A[g.front()])%mod) + mod)%mod;
    while(ans < 0) {
        ans+=mod;
    }
    return ans;
}

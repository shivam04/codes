int mod = 1000000007;
long long sumMinEle(vector<int> &A) {
    int n = A.size();
    long long left[n], right[n];
    stack<pair<int, long long> > s1, s2;
    for (int i = 0; i < n; ++i) {
        long long cnt = 1;
        while(!s1.empty() and s1.top().first > A[i]) {
            cnt += s1.top().second;
            s1.pop();
        }
        s1.push({A[i], cnt});
        left[i] = cnt;
    }

    for (int i = n-1; i >=0; --i) {
        long long cnt = 1;
        while(!s2.empty() and s2.top().first >= A[i]) {
            cnt += s2.top().second;
            s2.pop();
        }
        s2.push({A[i], cnt});
        right[i] = cnt;
    }

    long long ans = 0;
    for(int i=0;i<n;i++) {
        long long a = A[i];
        ans = (ans%mod + (a%mod*left[i]%mod*right[i]%mod)%mod)%mod;
    }
    return ans;
}

long long sumMaxEle(vector<int> &A) {
    int n = A.size();
    long long left[n], right[n];
    stack<pair<int, long long> > s1, s2;
    for (int i = 0; i < n; ++i) {
        long long cnt = 1;
        while(!s1.empty() and s1.top().first < A[i]) {
            cnt += s1.top().second;
            s1.pop();
        }
        s1.push({A[i], cnt});
        left[i] = cnt;
    }

    for (int i = n-1; i >=0; --i) {
        long long cnt = 1;
        while(!s2.empty() and s2.top().first <= A[i]) {
            cnt += s2.top().second;
            s2.pop();
        }
        s2.push({A[i], cnt});
        right[i] = cnt;
    }

    long long ans = 0;
    for(int i=0;i<n;i++) {
        long long a = A[i];
        ans = (ans%mod + (a%mod*left[i]%mod*right[i]%mod)%mod)%mod;
    }
    return ans;
}
int Solution::solve(vector<int> &A) {
    
    long long miniSum = sumMinEle(A);
    long long maxiSum = sumMaxEle(A);
    return (maxiSum - miniSum + mod)%mod;
}

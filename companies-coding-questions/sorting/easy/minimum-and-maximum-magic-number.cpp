//O(N) memory
#define MOD 1000000007;
vector<int> Solution::solve(vector<int> &A) {
    vector<int> v1, v2;
    sort(A.begin(), A.end());
    int n = A.size();
    for(int i=0;i<n/2;i++) {
        v1.push_back(A[i]);
    }

    for(int i=n/2;i<n;i++) {
        v2.push_back(A[i]);
    }

    long maxS = 0;
    for(int i=0;i<n/2;i++) {
        maxS = maxS + abs(v1[i]-v2[i]);
        maxS%=MOD;
    }

    v1.clear();
    v2.clear();
    for(int i=0;i<n;i++) {
        if(i%2) {
            v1.push_back(A[i]);
        } else {
            v2.push_back(A[i]);
        }
    }

    long minS = 0;
    for(int i=0;i<n/2;i++) {
        minS = minS + abs(v1[i]-v2[i]);
        minS%=MOD;
    }
    return {maxS, minS};
}


//O(1) Memory
#define MOD 1000000007;
vector<int> Solution::solve(vector<int> &A) {
    vector<int> v1, v2;
    sort(A.begin(), A.end());
    int n = A.size();
    long maxS = 0;
    for(int i=0;i<n/2;i++) {
        maxS += abs(A[i]-A[n-i-1]);
        maxS%=MOD;
    }
    long minS = 0;
    for(int i=0;i<n;i+=2) {
        minS += abs(A[i]-A[i+1]);
        minS%=MOD;
    }
    return {maxS, minS};
}
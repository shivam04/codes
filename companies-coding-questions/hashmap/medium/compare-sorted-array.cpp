unordered_map<int, long long> createHash(vector<int> A) {
    srand(time(0));
    long long max= 1000000000000;
    long long min = 0;
    unordered_map<int, long long> mp;
    for(int i=0;i<A.size();i++) {
        long long output = min + i + (rand() * (int)(max - min + i) / RAND_MAX);
        if(mp.find(A[i]) == mp.end()) {
            mp[A[i]] = output;
        }
    }
    return mp;
}
vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    unordered_map<int, long long> mp = createHash(A);
    int n = A.size();
    long long prefix[n+1];
    prefix[0] = 0;
    for(int i=0;i<n;i++) {
        prefix[i+1] = prefix[i] + mp[A[i]];
    }
    int q = B.size();
    int i = 0;
    vector<int> anss;
    while(i<q) {
        int l1 = B[i][0]+1;
        int r1 = B[i][1]+1;
        int l2 = B[i][2]+1;
        int r2 = B[i][3]+1;
        if(r2-l2==r1-l1) {
            long long sum1 = prefix[r1] - prefix[l1-1];
            long long sum2 = prefix[r2] - prefix[l2-1];
            anss.push_back(sum1==sum2);
        } else {
            anss.push_back(0);
        }
        i++;
    }
    return anss;
}

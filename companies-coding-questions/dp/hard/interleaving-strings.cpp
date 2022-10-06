unordered_map<int,unordered_map<int,bool>> dp;
int isInterleaveUtil(string A, string B, string C, int i, int j) {
    int k = i+j;
    if(k==C.size()) {
        return 1;
    }
    if(dp.find(i) != dp.end() and dp[i].find(j)!=dp[i].end()) {
        return dp[i][j];
    }
    if(i<A.size() and A[i]==C[k]) { 
        if(isInterleaveUtil(A, B, C, i+1, j))
            return dp[i][j] = 1;
    }

    if(j<B.size() and B[j]==C[k]) {
        if(isInterleaveUtil(A, B, C, i, j+1))
            return dp[i][j] = 1;
    }
    return dp[i][j] = 0;
}
int Solution::isInterleave(string A, string B, string C) {
    dp.clear();
    if(C.size() != A.size() + B.size())
        return 0;
    return isInterleaveUtil(A, B, C, 0, 0);
}

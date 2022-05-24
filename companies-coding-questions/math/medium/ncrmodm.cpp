int Solution::solve(int A, int B, int C) {
    int comb[B+1]; 
    memset(comb, 0, sizeof(comb)); 
    comb[0] = 1;
    for (int i = 1; i <= A; i++) {
        for (int j = min(i, B); j > 0; j--)  {
            comb[j] = (comb[j] + comb[j-1])%C; 
        }
    }
    return comb[B];
}

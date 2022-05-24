int solveUTIL(int n) {
    if(n==0)
        return 0;
    return n%10 + solveUTIL(n/10);
}
int Solution::solve(int A) {
    if(A==1)
        return 1;
    else if(A>=2 and A<=9)
        return 0;
    return solve(solveUTIL(A));
}

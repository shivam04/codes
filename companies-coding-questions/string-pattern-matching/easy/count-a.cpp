int Solution::solve(string A) {
    long n = 0;
    for(char c: A) {
        n += (c=='a');
    }
    return (n*(n+1)/2);
}

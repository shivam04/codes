unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==0)
        return A;
    vector<int> p(32, 0);
    int j = 31;
    while(A) {
        p[j--] = A%2;
        A>>=1;
    }
    unsigned int ans = 0;
    for(int i=31;i>=0;i--) {
        if(p[i]==1)
            ans += (1<<i);
    }
    return ans;
}
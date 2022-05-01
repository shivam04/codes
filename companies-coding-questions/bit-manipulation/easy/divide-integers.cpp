int Solution::divide(int A, int B) {
    int neg = (A<0) ^ (B<0) ? -1 : 1;
    if(A==INT_MIN and B==1) {
        return A;
    } else if(A==INT_MIN and B==-1) {
        return INT_MAX;
    }
    if(A==INT_MIN)
        A = INT_MAX;
    if(B==INT_MIN)
        B=INT_MAX;
    A = abs(A);
    B = abs(B);
    int q = 0;
    while(A>=B) {
        A-=B;
        ++q;
    }
    return neg*q;
}

int Solution::pow(int A, int B, int C) {
    if(A==0)
        return 0;
    if(B==0)
        return 1;
    long a;
    if(B%2==0) {
        a = pow(A,B/2,C);
        a = (a*a)%C;
    } else {
        a = A%C;
        a = (a*pow(A,B-1,C)%C)%C;
    }
    return (int)((a + C) % C);
    
}

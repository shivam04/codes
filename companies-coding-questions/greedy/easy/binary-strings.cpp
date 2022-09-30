int Solution::solve(string A, int B) {
    int result=0;
    int c=0;
    int n = A.size();
    vector<int> total(n,0);
    vector<int> f(n,0);
    for(int i=0;i<(int)A.size();i++) {
        if(i>=B and total[i-B]==1) {
            c--;
        }
        if((A[i]-48 + c)%2==0) {
            if(i<(int)A.size()-B+1) {
                result++;
                c++;
            }
            total[i] = 1;
        }
        f[i]=c;
    }
    for(int i=(int)A.size()-B;i<A.size();i++) {
        if((A[i]-48+f[i])%2==0) {
            return -1;
        }
    }
    return result;
}
int Solution::strStr(const string A, const string B) {
    int M = B.length();
    vector<int> lps(M);
    lps[0]=0;
    int i = 1;
    int len = 0;
    while(i<M){
        if(B[i]==B[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    i = 0;
    int j = 0;
    int N =A.length();
    while(i<N){
        if(A[i]==B[j]){
            i++;
            j++;
        }
        if(j==M){
            return i-M;
        }
        else if(i<N and A[i]!=B[j]){
            if(j!=0)
            j = lps[j-1];
            else
            i++;
        }
    }
    return -1;
}

int Solution::compareVersion(string A, string B) {
    string num1="1";
    string num2="1";
    int N = A.length();
    int M = B.length();
    int i=0,j=0;
    while(i<N||j<M){
        while(i<N and A[i]=='0')
        i++;
        while(i<A.length() && A[i]!='.'){
            num1+=A[i];
            i++;
        }
        while(j<B.length() && B[j]=='0'){
                j++;
        }
            
        while(j<B.length() && B[j]!='.'){
            num2+=B[j];
            j++;
        }
        if(num1!=num2){
            if(num1.length()==num2.length())
                return num1>num2?1:-1;
            else
                return num1.length()>num2.length() ? 1:-1;
        }
        i++;
        j++;
    }
    if(i>=N && j>=M)
        return 0;
    return i>j?1:-1;
}

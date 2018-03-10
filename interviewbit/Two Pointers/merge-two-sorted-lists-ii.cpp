void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> C;
    int i = 0,j=0,k=0;
    int m = A.size();
    int n = B.size();
    C.resize(m+n);
    while(i<m and j<n){
        if(A[i]<=B[j]){
            C[k++]=A[i++];
        }else{
            C[k++]=B[j++];
        }
    }
    while(i<m){
        C[k++]=A[i++];
    }
    while(j<n){
        C[k++]=B[j++];
    }
    A.resize(m+n);
    for(i=0;i<m+n;i++){
        A[i]=C[i];
    }
}

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int j =0;
    int i;
    int n = A.size();
    for(i=0;i<n;i++){
        if(A[i]!=A[i+2] || (i+2)>=n){
            A[j++]=A[i];
        }
    }
    /*A[j++]=A[n-2];
    A[j++]=A[n-1];*/
    return j;
}

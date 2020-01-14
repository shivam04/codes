vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> v;
    int k = lower_bound(A.begin(),A.end(),B)-A.begin();
    if(A[k]==B){
        v.push_back(k);
    }else{
        v.push_back(-1);
    }
    k = upper_bound(A.begin(),A.end(),B)-A.begin();
    if(A[k-1]==B){
        v.push_back(k-1);
    }else{
        v.push_back(-1);
    }
    return v;
}

vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size();
    for(int i=0;i<n;i+=2){
        if(i+1==n)
        break;
        A[i] = A[i]+A[i+1];
        A[i+1] = A[i]-A[i+1];
        A[i] = A[i] - A[i+1];
    }
    return A;
}

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<int> LMin(n+1);
    vector<int> RMax(n+1);
    LMin[0] = A[0];
    for(int i=1;i<n;i++){
        LMin[i] = min(LMin[i-1],A[i]);
    }
    RMax[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--){
        RMax[i] = max(RMax[i+1],A[i]);
    }
    int i=0,j=0;
    int maxi=-1;
    while(i<n and j<n){
        if(LMin[i]<=RMax[j]){
            maxi = max(maxi,j-i);
            j+=1;
        }
        else
            i+=1;
    }
    return maxi;
}

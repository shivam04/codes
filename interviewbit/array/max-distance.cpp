int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<bool> tt(n);
    int i = n-1;
    int j = n-1;
    int mini = A[0];
    int maxi = -1;
    for(int i=0;i<n;i++){
        if(A[i]>mini){
            tt[i]=false;
        }else{
            mini = A[i];
            tt[i] = true;
        }
    }
    while(i>=0){
        if(tt[i]==false){
            i--;
            continue;
        }
        while((A[i]>A[j])and(j>i)){
            j--;
        }
        if((j-i)>maxi){
            maxi = j-i;
        }
        i--;
    }
    return maxi;
}

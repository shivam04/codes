int Solution::books(vector<int> &A, int B) {
    int maxi = *max_element(A.begin(),A.end());
    if(A.size()==B){
        return maxi;
    }
    if(A.size()<B){
        return -1;
    }
    int n = A.size();
    //int prefix[n+1];
    int i;
    int sum=A[0];
    for(i=1;i<n;i++){
        sum+=A[i];
    }
    int l = 0;
    int r = sum;
    while(l<r){
        int mid = (l+r)/2;
        if(maxi>mid){
            l=mid+1;
        }else{
            int s = 0;
            int p = 0;
            for(i=0;i<n;i++){
                s+=A[i];
                if(s>mid){
                    s=A[i];
                    p++;
                }
            }
            if(p<B){
                r=mid;
            }else{
                l=mid+1;
            }
        }
    }
    return l;
}

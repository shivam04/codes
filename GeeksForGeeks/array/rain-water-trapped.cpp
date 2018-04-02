int Solution::trap(const vector<int> &A) {
    int i;
    int ans = 0;
    int l=0;
    int h = A.size()-1;
    int l_max = INT_MIN;
    int h_max = INT_MIN;
    while(l<=h){
        if(A[l]<A[h]){
            if(A[l]>l_max)
            l_max = A[l];
            else
            ans+=(l_max-A[l]);
            l++;
        }else{
            if(A[h]>h_max)
            h_max = A[h];
            else
            ans+=(h_max-A[h]);
            h--;
        }
    }
    return ans;
}

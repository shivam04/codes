int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n = A.size();
    int l,r=n-1;
    int mini = INT_MAX;
    int ans;
    for(int i=0;i<n-2;i++){
        l = i+1;
        r = n-1;
        while(l<r){
            if(A[i]+A[l]+A[r]==B){
                return A[i]+A[l]+A[r];
            }
            else if(A[i]+A[l]+A[r]>B){
                if((A[i]+A[l]+A[r])<=mini){
                    mini = A[i]+A[l]+A[r]-B;
                    ans =A[i]+A[l]+A[r];
                }
                r--;
            }else{
                if((A[i]+A[l]+A[r])<=mini){
                    mini = B-(A[i]+A[l]+A[r]);
                    ans =A[i]+A[l]+A[r];
                }
                l++;
            }
        }
    }
    return ans;
}

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int l = 0;
    int r = A.size()-1;
    if(r==0)
    return A[r];
    int mid=-1;
    int flag = 0;
    while(l<=r){
        mid = (l+r)/2;
        if(mid<r and A[mid]>A[mid+1])
        {
            flag = 1;
            break;
        }else if(mid>l and A[mid]<A[mid-1]){
            flag = 1;
            mid--;
            break;
        }else if(A[l]>=A[mid]){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
   // cout<<flag<<"\n";
    if(!flag){
        int l=0;
        r = A.size()-1;
        if(binary_search(A.begin(),A.end(),B)){
            int k =lower_bound(A.begin(),A.end(),B)-A.begin();
            return k;
        }else{
            return -1;
        }
    }
//cout<<mid<<"\n";
    //cout<<binary_search(A.begin()+mid+1,A.end(),B)<<"\n";
    if(binary_search(A.begin(),A.begin()+mid+1,B)){
       return lower_bound(A.begin(),A.begin()+mid+1,B)-A.begin(); 
    }else{
        if(binary_search(A.begin()+mid+1,A.end(),B)){
            int k=lower_bound(A.begin()+mid+1,A.end(),B)-A.begin(); 
            //cout<<k<<"\n";
            return k;
        }else{
            return -1;
        }
    }

}

bool isPossible(int A, int B, vector<int> &C,long long int X){
    int n=C.size();
   long long int t=X;
    int i=0,cnt=1;
    while(i<n){
        if(cnt>A)
         return false;
        if(C[i]>t){
            cnt++;
            t=X;
        }
        else{
            t=t-C[i];
            i++;
        }
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int n=C.size();
    long long int sum=0;
    for(int i=0;i<n;i++)
     sum=sum%10000003+C[i]%10000003;
    long long int low=0,high=sum*B;
    long long int ans=high%10000003;
    while(low<=high){
        long long int mid=low+(high-low)/2;
        if(isPossible(A,B,C,mid/B)){
            ans=mid%10000003;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans%10000003;
}
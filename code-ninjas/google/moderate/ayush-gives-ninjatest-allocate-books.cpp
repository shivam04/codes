bool isPossible(int A, vector<int> &C,long long int X){
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
long long ayushGivesNinjatest(int n, int m, vector<int> time) {
    if(m<n) {
        return -1;
    }
    long long int sum=0;
    for(int i=0;i<m;i++)
     sum += time[i];
    long long int low=0,high=sum;
    long long int ans = -1;
    while(low<=high){
        long long int mid=low+(high-low)/2;
        if(isPossible(n,time,mid)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
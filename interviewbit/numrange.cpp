int Solution::numRange(vector<int> &A, int B, int C) {
    int l=0;
    int r=0;
    int n = A.size();
    int count = 0;
    int sum = 0;
    while(l<n){
        sum = sum+A[r];
        if(sum>=B and sum<=C){
            count++;
            r++;
        }
        else if(sum<B)
        r++;
        else if(sum>C){
            sum = 0;
            l++;
            r= l;
        }
        if(r==n){
            sum=0;
            l++;
            r=l;
        }
    }
    return count;
}

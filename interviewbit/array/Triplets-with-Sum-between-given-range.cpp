int Solution::solve(vector<string> &A) {
    sort(A.begin(),A.end());
    double sum = stof(A[0])+stof(A[1])+stof(A[2]);
    int n = A.size();
    if(sum>2)
    return 0;
    if(1<sum and sum<2)
    return 1;
    for(int i=3;i<n;i++){
        if(sum<1){
            sum-=stof(A[i-3]);
            sum+=stof(A[i]);
        }else if(sum>1 and sum<2){
            return 1;
        }else if(sum>2){
            sum=0;
        }
    }
    if(sum<1)
    return 0;
    if(sum>1 and sum<2)
    return 1;
    return 0;
}

int max_sum(int A[],int N)
{
    int i;
    int asum = 0;
    int csum =0;
    for(i=0;i<N;i++){
        asum = asum + A[i];
        csum = csum + i*A[i];
    }
    int msum = csum;
    for(i=1;i<N;i++){
        csum = csum + asum-N*A[N-i];
        msum = max(csum,msum);
    }
    return msum;
}
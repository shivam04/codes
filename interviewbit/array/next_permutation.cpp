void swap(int *a,int *b)
{
    if( *a == *b )
        return;
    *a^=*b;
    *b^=*a;
    *a^=*b;
}
void rev(vector<int> &s,int l,int r)
{
    while(l<r)
        swap(&s[l++],&s[r--]);
}
void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int i = n-2;
    while(i>=0 and A[i]>=A[i+1])
    i--;
    if(i<0){
        //cout<<"yo\n";
        int i = n-1;
        while (i > 0 && A[i - 1] <= A[i])
            i--;
        int j = i - 1;
        while (j + 1 <= n && A[j + 1] <= A[i - 1])
            j++;
        swap(&A[i - 1], &A[j]);
        rev(A,i,n-1);
        return ;
    }
    int l = i+1;
    int r = n-1;
    int ans=-1;
    int key = A[i];
    while(l<=r){
        int mid = l+(r-l)/2;
        if(A[mid]<=key)
            r=mid-1;
        else
        {
            l=mid+1;
            if(ans = -1 || A[ans]<=A[mid])
                ans = mid;
        }
    }
    swap(&A[i],&A[ans]);
    rev(A,i+1,n-1);
}

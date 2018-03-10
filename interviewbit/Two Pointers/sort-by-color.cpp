void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int r=0,w=0,b=0;
    int i;
    int n = A.size();
    for(i=0;i<n;i++){
        if(A[i]==0)
        r++;
        else if(A[i]==1)
        w++;
        else
        b++;
    }
    int j=0,k=r,l=r+w;
    //cout<<r<<" "<<w<<" "<<b<<" "<<j<<" "<<k<<" "<<l<<"\n";
    vector<int> B;
    B.resize(n);
    for(i=0;i<n;i++){
        if(A[i]==0)
        B[j++]=0;
        else if(A[i]==1)
        B[k++]=1;
        else if(A[i]==2)
        B[l++]=2;
    }
    //cout<<B.size()<<"\n";;
    A.resize(n);
    for(i=0;i<n;i++)
    A[i]=B[i];
}

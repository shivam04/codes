vector<int> Solution::maxone(vector<int> &A, int B) {
    int l=0,r=0;
    int n = A.size();
    int zC = 0;
    int si = 0;
    int maxi = 0;
    while(r<n){
        if(zC<=B){
            if(A[r]==0)
                zC++;
            r++;
        }
        if(zC>B){
            if(A[l]==0)
                zC--;
            l++;
        }
        if(r-l>maxi){
            maxi = r-l;
            si = l;
        }
    }
    //cout<<l<<" "<<r<<"\n";
    //cout<<maxi<<" "<<si<<"\n";
    vector<int> v;
    int i;
    for(i=si;i<si+maxi;i++)
    v.push_back(i);
    return v;
}

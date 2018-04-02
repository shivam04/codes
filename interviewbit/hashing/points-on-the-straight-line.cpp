struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return (1.0*(h1/h2));  
    }
};
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() == 0 || B.size() == 0){
        return 0;
    }
    unordered_map<pair<int,int> ,int,pair_hash> slopeMap;
    int omaxi,vmaxi,maxim ;
    int ans = INT_MIN;
    for(int i=0;i<A.size();i++){
        maxim=omaxi = vmaxi=0;
        for(int j=i+1;j<B.size();j++){
            if(A[i]==A[j] and B[i]==B[j])
            omaxi++;
            else if(A[i]==A[j])
            vmaxi++;
            else{
                int y = B[i]-B[j];
                int x = A[i]-A[j];
                int g = __gcd(x,y);
                y/=g;
                x/=g;
                pair<int,int> p =make_pair(y, x);
                if(slopeMap.find(p)!=slopeMap.end()){
                    slopeMap[p]+=1;
                }else{
                    slopeMap[p]=1;
                }
                maxim = max(maxim, slopeMap[p]);
            }
            maxim = max(maxim,vmaxi);
        }
        ans = max(ans,maxim+omaxi+1);
        slopeMap.clear();
    }
    return ans;
}

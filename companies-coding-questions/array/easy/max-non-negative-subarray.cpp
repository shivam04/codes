vector<int> Solution::maxset(vector<int> &A) {
    long cnt = 0;
    long maxC = 0;
    int s = 0;
    int start = -1;
    int end = -1;
    int allNeg = 1;
    for(int i=0;i<A.size();i++) {
        if(A[i]<0) {
            s = i+1;
            cnt = 0;
        } else {
            allNeg = 0;
            cnt += A[i];
        }
        if(maxC < cnt) {
            maxC = cnt;
            start = s;
            end = i;
        }
    }
    vector<int> ans;
    if(allNeg) {
        return ans;
    }
    int allZero = 1;
    for(int num: A) {
        if(num!=0) 
            allZero = 0;
    }
    if(allZero)
        return A;
    int allZeoAndNeg = 1;
    for(int num: A) {
        if(num>0) 
            allZeoAndNeg = 0;
    }
    if(allZeoAndNeg) {
        int maxCC = 0;
        int cC = 0;
        for(int i=0;i<A.size();i++) {
            if(A[i]==0) {
                cC +=1;
            } else {
                cC = 0;
            }
            maxCC = max(maxCC,cC);
        }
        for(int i=0;i<maxCC;i++) {
            ans.push_back(0);
        }
        return ans;
    }
    for(int i=start;i<=end;i++) {
        ans.push_back(A[i]);
    }
    return ans;
}

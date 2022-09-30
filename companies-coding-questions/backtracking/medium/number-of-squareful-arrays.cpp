bool square(int s) {
    int q = ((int)sqrt(s)*(int)sqrt(s));
    return q==s;
}
void ans(vector<int> &k,vector<int> A, int &res, int vis) {
    if(k.size()==A.size()){
        bool isSqA = true;
        for(int i=1;i<A.size();i++) {
            if(!square(k[i]+k[i-1])) {
                isSqA = false;
                break;
            }
        }
        if(isSqA)
        res++;
        return;
    } else if(k.size() <= 1 or square(k[k.size()-1] + k[k.size()-2])) {
        for(int i=0;i<A.size();i++) {
            if((vis & (1 << i)) > 0) continue;
            if(i > 0 && A[i] == A[i - 1] && (vis & (1 << (i - 1))) == 0) continue;
            k.push_back(A[i]);
            ans(k,A,res, vis | (1<<i));
            k.pop_back();
        }
    }
}

int Solution::solve(vector<int> &A) {
    if(A.size()<=1)
        return 0;
    sort(A.begin(), A.end());
    vector<int> k;
    int res = 0;
    ans(k, A, res, 0);
    return res;
}

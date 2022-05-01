int Solution::solve(int A, int B) {
    vector<short int> s;
    while(A) {
        s.push_back(A%2);
        A>>=1;
    }
    int ans = 0;
    for(int i=s.size()-1;i>=0;i--) {
        if(s[i]==1 and B>0) {
            B--;
            ans |= (1<<i);
        }
    }
    for(int i=0;i<s.size() and B>0;i++) {
        if(s[i]==0 and B>0) {
            B--;
            ans |= (1<<i);
        }
    }
    int k = s.size();
    while(B--) {
        ans |= (1<<k);
        k++;
    }
    s.clear();
    return ans;
}

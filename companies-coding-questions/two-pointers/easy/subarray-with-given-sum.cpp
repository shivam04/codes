vector<int> Solution::solve(vector<int> &A, int B) {
    int st = 0;
    int s = 0;
    int n = A.size();
    for(int i=0;i<n;i++) {
        s+=A[i];
        if(s==B) {
            return vector<int>(A.begin()+st,A.begin()+i+1);
        }
        while(s>B) {
            s -= A[st];
            st++;
        } 
        if(s==B) {
            return vector<int>(A.begin()+st,A.begin()+i+1);
        }
    }
    return {-1};
}
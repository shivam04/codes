//O(nlogn) -> time, O(n) -> space
int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int l = 0;
    int r = 1;
    set<pair<int,int>> s;
    while(r<A.size()) {
        if(r != l and A[r]-A[l]==B) {
            s.insert({A[l],A[r]});
            l++;
            r++;
        } else if(A[r]-A[l] < B) {
            r++;
        } else {
            l++;
        }
    }
    return s.size();
}
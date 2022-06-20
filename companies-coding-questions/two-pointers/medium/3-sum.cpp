int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int ans = 1000000000000;
    int n = A.size();
    for(int i=0;i<n-2;i++) {
        int l = i+1;
        int h = n-1;
        while(l<h) {
            if(A[l] + A[h] + A[i] == B) {
                return B;
            }
            int x = A[l] + A[h] + A[i];
            if (abs(x - B) < abs(ans - B)) {
                ans = x;
            } 
            if(x > B) {
                h--;
            } else {
                l++;
            }
        }
    }
    return ans;
}

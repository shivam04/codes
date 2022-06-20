vector<int> Solution::sortColors(vector<int> &A) {
    int z=0,o=0,t=0;
    int n = A.size();
    int i = 0;
    while(i<n) {
        z+=(A[i]==0);
        o+=(A[i]==1);
        t+=(A[i]==2);
        i++;
    }
    i = 0;
    while(z--) {
        A[i++] = 0;
    }
    while(o--) {
        A[i++] = 1;
    }
    while(t--) {
        A[i++] = 2;
    }
    return A;
}

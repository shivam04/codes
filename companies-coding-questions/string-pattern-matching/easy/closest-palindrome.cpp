string Solution::solve(string A) {
    int i = 0;
    int j = A.size()-1;
    int diff = 0;
    while(i<j) {
        diff += (A[i]!=A[j]);
        i++;
        j--;
    }
    if(diff==0) {
        if(A.size()%2==0) {
            return "NO";
        } else {
            return "YES";
        }
    }
    return diff<=1 ? "YES" : "NO";
}

bool allNines(string A, int n) {
    for(int i=0;i<n;i++) {
        if(A[i] != '9')
            return false;
    }
    return true;
}
string Solution::solve(string A) {
    int n = A.size();
    if(allNines(A, n)) {
        string ans = "1";
        for(int i=1;i<n;i++) {
            ans += "0";
        }
        ans += "1";
        return ans;
    }
    int mid = n/2;
    bool leftHalfSmall = false;
    int i = mid-1;
    int j = (n%2) ? mid + 1: mid;
    while(i>=0 and A[i]==A[j]) {
        i--;
        j++;
    }
    if(i<0 || A[i] < A[j])
        leftHalfSmall = true;
    while(i>=0) {
        A[j] = A[i];
        i--;
        j++;
    }
    if(leftHalfSmall) {
        i = mid-1;
        int carry = 1;
        if(n%2==1) {
            int num = A[mid] - 48;
            num = num + carry;
            carry = num/10;
            num = num%10;
            A[mid] = (char)(num + 48);
            j = mid+1;
        } else {
            j = mid;
        }
        while(i>=0) {
            int num = A[i] - 48;
            num = num + carry;
            carry = num/10;
            num = num%10;
            A[i] = (char)(num + 48);
            A[j] = A[i];
            i--;
            j++;
        }
    }
    return A;
}

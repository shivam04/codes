int Solution::solve(vector<int> &A, int B) {
    int mod = 1000000007;
    sort(A.begin(), A.end());
    long cnt = 0;
    int l = 0;
    int r = A.size() - 1;
    for(int i=0;i<r;i++) {
        int k = B-A[i];
        int x = lower_bound(A.begin() + i + 1, A.end(), k) - A.begin();
        int y = upper_bound(A.begin() + i + 1, A.end(), k) - A.begin();
        cnt = cnt + (y - x);
        cnt%=mod;
    }
    return cnt;
}




const int mod = (int)(1e9 + 7);
int Solution::solve(vector < int > & A, int B) {
    int n = A.size(), i = 0, j = n - 1;
    long count = 0;
    while (i < j) {
        int sum = A[i] + A[j];
        if (sum == B) {
             if (A[i] != A[j]) {
                int a = 1, b = 1;
                while (i + 1 < j && A[i] == A[i + 1]) i++, a++;
                while (j - 1 > i && A[j] == A[j - 1]) j--, b++;
                count = (count + (a * 1l * b) % mod) % mod;
                i++, j--;
            } else { 
                int cnt = 1;
                cnt = (j - i + 1);
                cnt = (cnt * 1ll * (cnt - 1) / 2) % mod;
                count = (cnt + count) % mod;
                break;
            }
        } else if (sum > B)
            j--;
        else i++;
    }
    return count;
}
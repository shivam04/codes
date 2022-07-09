int solveUtil(vector<int> &arr) {
    vector<int> stack;
    int n = arr.size();
    int res = 0, l = 0, i;
 
    for (i = 0; i < n; i++) {
        while (!stack.empty() &&
                stack.back() < arr[i]) {
            stack.pop_back();
            l--;
        }
        stack.push_back(arr[i]);
        l++;
        if (l > 1) {
            res = max(res,
             stack[l - 1] ^ stack[l - 2]);
        }
    }
    return res;
}
int Solution::solve(vector<int> &A) {
    int f = solveUtil(A);
    reverse(A.begin(), A.end());
    int s = solveUtil(A);
    return max(f,s);
}

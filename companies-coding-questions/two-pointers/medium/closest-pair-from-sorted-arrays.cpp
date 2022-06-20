vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int i = 0;
    int n = A.size(), m = B.size();
    int j = m-1;
    int res_i = 0, res_j=0;
    int diff = INT_MAX;
    while(i<n and j>=0) {
        int x = A[i] + B[j];
        if(abs(x-C) < diff) {
            diff = abs(x-C);
            res_i = i;
            res_j = j;
        }

        if(abs(x-C)==diff) {
            if(i<res_i) {
                res_i = i;
                res_j = j;
            } else if(i==res_i and j<res_j) {
                res_j = j;
            }
        }

        if(abs(x-C)==0) {
            break;
        }

        if(x>C) {
            j--;
        } else {
            i++;
        }
    }
    return {A[res_i], B[res_j]};
}

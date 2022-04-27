int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();

    vector<vector<int>> prefixT;

    for(int j=0;j<n;j++) {
        vector<int> pp;
        int sum = 0;
        for (int i=0; i<B; i++)
            sum += A[i][j];
        pp.push_back(sum);
        for(int i=B;i<n;i++) {
            sum = sum + A[i][j] - A[i-B][j];
            pp.push_back(sum);
        }
        prefixT.push_back(pp);
    }

    int maxi = INT_MIN;
    int mm = prefixT[0].size();
    for(int j=0;j<mm;j++) {
        vector<int> pp;
        int sum = 0;
        for (int i=0; i<B; i++)
            sum += prefixT[i][j];
        maxi = max(maxi, sum);
        for(int i=B;i<n;i++) {
            sum = sum + prefixT[i][j] - prefixT[i-B][j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

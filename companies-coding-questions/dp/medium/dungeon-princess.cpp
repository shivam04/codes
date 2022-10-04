int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int m=A.size(), n=A[0].size();
        
        vector<vector<int>> game(m, vector<int>(n, 0));
        game[m-1][n-1]=max(1, 1-A[m-1][n-1]);

        for(int i=m-2; i>=0; i--) game[i][n-1]=max(1, -(A[i][n-1]-game[i+1][n-1]));
        for(int j=n-2; j>=0; j--) game[m-1][j]=max(1, -(A[m-1][j]-game[m-1][j+1]));

        for(int i=m-2; i>=0; i--) {
            for(int j=n-2; j>=0; j--) {
                game[i][j]=min(max(1, -(A[i][j]-game[i+1][j])), max(1, -(A[i][j]-game[i][j+1])));

            }
        }
        
        return game[0][0];
}

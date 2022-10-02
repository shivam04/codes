vector<vector<int>> board;
bool solveUtil(vector<vector<int> > &A, int row, int col, int n) {
    if(row >= n or col >= n)
        return false;
    if(row==n-1 and col==n-1) {
        board[row][col] = 1;
        return (A[row][col]==1);
    }
    if(A[row][col]==0)
        return false;
    board[row][col] = 1;
    if(solveUtil(A, row+1, col, n) || solveUtil(A, row, col+1, n)) {
        return true;
    }
    board[row][col] = 0;
    return false;
}

vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    board.clear();
    int n = A.size();
    for(int i=0;i<n;i++) {
        vector<int> row;
        for(int j=0;j<n;j++) {
            row.push_back(0);
        }
        board.push_back(row);
    }
    solveUtil(A, 0, 0, n);
    return board;
}
vector<vector<string> > ans;
bool isSafe(vector<string> board, int r, int c, int n) {
    int i,j;
    for(i=0;i<c;i++) {
        if(board[r][i]=='Q')
            return false;
    }
    for(i=r,j=c;i>=0 and j>=0;i--,j--) {
        if(board[i][j]=='Q')
            return false;
    }

    for(i=r,j=c;j>=0 and i<n;i++,j--) {
        if(board[i][j]=='Q')
            return false;
    }
    return true;
}
void checkANS(vector<string> board, int r, int c) {
    if(c>=r) {
        ans.push_back(board);
    }
    for (int i = 0; i < r; i++) {
        if(isSafe(board, i, c, r)) {
            board[i][c] = 'Q';
            checkANS(board, r, c+1);
            board[i][c] = '.';
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    ans.clear();
    vector<string> board;
    for(int i=0;i<A;i++) {
        string row = "";
        for(int j=0;j<A;j++) {
            row.push_back('.');
        }
        board.push_back(row);
    }
    checkANS(board, A, 0);
    return ans;
}

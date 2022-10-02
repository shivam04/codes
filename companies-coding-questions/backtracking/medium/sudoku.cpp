bool FindUnassignedLocation(vector<vector<char> > &A, int &row, int &col) {
    for (row = 0; row < A.size(); row++) {
        for (col = 0; col < A.size(); col++) {
            if (A[row][col] == '.')
                return true;
        }
    }
    return false;
}

bool UsedInRow(vector<vector<char>> &A, int row, char num) {
    for (int col = 0; col < A.size(); col++) {
        if(A[row][col] == num)
            return true;
    }
    return false;
}

bool UsedInCol(vector<vector<char>> &A, int col, char num) {
    for (int row = 0; row < A.size(); row++) {
        if(A[row][col]== num)
            return true;
    }
    return false;
    
}

bool UsedInBox(vector<vector<char>> &A, int startRow, int startCol, char num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if(A[startRow+row][startCol+col] == num)
                return true;
        }
    }
    return false;
}

bool isSafe(vector<vector<char>> &A, int row, int col, char num) {
    return !UsedInRow(A, row, num)
           && !UsedInCol(A, col, num)
           && !UsedInBox(A, row - row%3,
                         col - col%3, num) && A[row][col] == '.';
}

bool solveSudokuUtil(vector<vector<char> > &A) {
    int row,col;
    if (!FindUnassignedLocation(A, row, col))
        return true;
    for(int i=1;i<=9;i++) {
        if(isSafe(A, row, col, (char)(i+'0'))) {
            A[row][col] = (char)(i+'0');
            if(solveSudokuUtil(A))
                return true;
            A[row][col] = '.';
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    solveSudokuUtil(A);
}

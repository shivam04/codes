int floorMod(int x, int y) {
    return ((x % y) + y) % y;
}
vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> result (A, vector<int>(A));
    int cnt = 1;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int d = 0;
    int row = 0;
    int col = 0;
    while (cnt <= A * A) {
        result[row][col] = cnt++;
        int r = floorMod(row + dir[d][0], A);
        int c = floorMod(col + dir[d][1], A);
        if (result[r][c] != 0) d = (d + 1) % 4;
        row += dir[d][0];
        col += dir[d][1];
    }
    return result;
}

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> result (A, vector<int>(A));
    int cnt = 1;
    for (int layer = 0; layer < (A + 1) / 2; layer++) {
        for (int ptr = layer; ptr < A - layer; ptr++) {
                result[layer][ptr] = cnt++;
        }
        for (int ptr = layer + 1; ptr < A - layer; ptr++) {
            result[ptr][A - layer - 1] = cnt++;
        }
        for (int ptr = A - layer - 2; ptr >= layer; ptr--) {
            result[A - layer - 1][ptr] = cnt++;
        }
        for (int ptr = A - layer - 2; ptr > layer; ptr--) {
            result[ptr][layer] = cnt++;
        }
    }
    return result;
}

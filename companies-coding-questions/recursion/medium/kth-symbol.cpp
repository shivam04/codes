int solveUtil(int A, int B, string rowVal) {
    if(A==0) {
        return rowVal[B-1] - 48;
    }
    string newRowVal = "";
    for(char v: rowVal) {
        if(v=='0') {
            newRowVal += "01";
        } else {
            newRowVal += "10";
        }
    }
    return solveUtil(A-1,B,newRowVal);
}
int Solution::solve(int A, int B) {
    return solveUtil(A-1,B,"0");
}

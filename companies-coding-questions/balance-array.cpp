int Solution::solve(vector<int> &A) {
    int evenSum = 0;
    int oddSum = 0;
    int n = A.size();
    for(int i=0;i<n;i++) {
        if(i%2==0) {
            evenSum += A[i];
        } else {
            oddSum += A[i];
        }
    }
    int currEvenSum = 0, currOddSum = 0;
    int res = 0;
    for(int i=0;i<n;i++) {
        int newEvenSum = 0;
        int newOddSum = 0;
        if(i%2==0) {
            newEvenSum = oddSum - currOddSum + currEvenSum;
            currEvenSum += A[i];
            newOddSum = evenSum - currEvenSum + currOddSum;
        } else {
            newOddSum = evenSum - currEvenSum + currOddSum;
            currOddSum += A[i];
            newEvenSum = oddSum - currOddSum + currEvenSum;
        }
        if(newEvenSum == newOddSum) 
            res++;
    }
    return res;
}

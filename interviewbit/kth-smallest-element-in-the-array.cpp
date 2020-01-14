int Solution::kthsmallest(const vector<int> &A, int k) {
    int lo = *min_element(A.begin(), A.end());
    int hi = *max_element(A.begin(), A.end());
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int countLess = 0,countEqual = 0;
        for(int i=0;i<A.size();i++){
            if(A[i]<mid)
            countLess++;
            else if(A[i]==mid)
            countEqual++;
            if(countLess>=k)
            break;
        }
        if(countLess < k && countLess + countEqual >= k)
            return mid;
        else if (countLess>=k)
        hi = mid-1;
        else
        lo = mid+1;
    }
    return -1;
}

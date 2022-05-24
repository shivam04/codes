int merge(vector<int> &A, int l, int mid, int r) {
    int invCnt = 0;
    int j = mid+1;
    int i = l;
    for(i=l;i<=mid;i++) {
        bool found = false;
        while (j <= r) {
            long long a = (long long )A[i];
            long long b = (long long )A[j];
            if (a > 2 * b) {
                found = true;
            }
            else
                break;
            j++;
        }
        if(found) {
            invCnt += j-(mid+1);
            j--;
        }
    }

    vector<int> temp;
    i = l;
    j = mid+1;
    while(i<=mid and j<=r) {
        if(A[i]<=A[j]) {
            temp.push_back(A[i++]);
        } else {
            temp.push_back(A[j++]);
        }
    }
    while(i<=mid) {
        temp.push_back(A[i++]);
    }
    while(j<=r) {
        temp.push_back(A[j++]);
    }
    int idx = 0;
    for(int i=l;i<=r;i++) {
        A[i] = temp[idx++];
    }
    return invCnt;
}
int mergeSort(vector<int> &A, int i, int j) {
    int invCnt = 0;
    if(j>i) {
        int mid = (i+j)/2;
        invCnt += mergeSort(A, i, mid);
        invCnt += mergeSort(A, mid+1, j);
        invCnt += merge(A, i, mid, j);
    }
    return invCnt;
}
int Solution::solve(vector<int> &A) {
    return mergeSort(A, 0, A.size()-1);
}

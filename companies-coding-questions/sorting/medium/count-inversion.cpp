#define mod 1000000007
int merge(vector<int> &vec, vector<int> &temp, int l, int mid, int r) {
    int k = l;
    int i = l;
    int j = mid;
    int invCnt = 0;
    while(i<=mid-1 and j<=r) {
        if(vec[i]<=vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
            invCnt = (invCnt %mod + (mid-i+mod)%mod)%mod;
        }
    }
    while(i<=mid-1) {
         temp[k++] = vec[i++];
    }
    while(j<=r) {
        temp[k++] = vec[j++];
    }
    for (i = l; i <= r; i++) {
        vec[i] = temp[i];
    }
    return invCnt;
}

int mergeSortUtil(vector<int> &vec, vector<int> &temp, int i, int j) {
    int mid, invCnt = 0;
    if(j>i) {
        mid = (i+j)/2;
        invCnt = (invCnt%mod + mergeSortUtil(vec,temp,i,mid)%mod)%mod;
        invCnt = (invCnt%mod + mergeSortUtil(vec,temp,mid+1,j)%mod)%mod;
        invCnt = (invCnt%mod + merge(vec, temp, i, mid + 1, j)%mod)%mod;
    }
    return invCnt;
}
int mergeSort(vector<int> &vec) {
    vector<int> temp(vec.size());
    return mergeSortUtil(vec, temp, 0, vec.size()-1);
}  
int Solution::solve(vector<int> &A) {
    int ans = mergeSort(A);
    
    return ans;
}

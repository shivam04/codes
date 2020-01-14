int Solution::maxArea(vector<int> &A) {
    int l = 0;
    int r = A.size()-1;
    int n = r+1;
    int area = 0;
    while(l<r){
        area = max(area,min(A[l],A[r])*(r-l));
        if(A[l]<A[r])
        l++;
        else
        r--;
    }
    return area;
}

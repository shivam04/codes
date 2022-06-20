pair<int,int> getSlope(int x1, int x2, int y1, int y2) {
    pair<int,int> slope = {1,0};
    if(x1!=x2) {
        int xDiff = x1-x2;
        int yDiff = y1-y2;
        int gcd = __gcd(abs(xDiff), abs(yDiff));
        xDiff /= gcd;
        yDiff /= gcd;
        if(xDiff < 0) {
            xDiff *= -1;
            yDiff *= -1;
        }
        slope = {yDiff, xDiff};
    }
    return slope;
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    int maxPoint = 1;
    int n = A.size();
    for(int i=0;i<n;i++) {
        unordered_map<string, int> slopes;
        int cnt = 0;
        for(int j=i+1;j<n;j++) {
            if(A[i]==A[j] and B[i]==B[j]) {
                cnt++;
                continue;
            }
            pair<int,int> slope = getSlope(A[i], A[j], B[i], B[j]);
            string key = to_string(slope.first) + ":" + to_string(slope.second);
            if(slopes.find(key) == slopes.end())
                slopes[key] = 1;
            slopes[key]++;
        }
        for(auto it: slopes) {
            maxPoint = max(maxPoint, it.second+cnt);
        }
    }
    return maxPoint;
}

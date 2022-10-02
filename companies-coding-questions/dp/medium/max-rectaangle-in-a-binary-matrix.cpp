int largestRectangleArea(vector<int> &A) {
    int ma = -1;
    int i = 0;
    stack<int> s;
    while(i<A.size()) {
        if(s.empty() or A[s.top()] < A[i]) {
            s.push(i);
            i++;
            continue;
        }
        int tp = s.top();
        s.pop();
        int area = A[tp]*((s.empty())?i:i-s.top()-1);
        ma = max(area, ma);
    }
    while(!s.empty()) {
        int tp = s.top();
        s.pop();
        int area = A[tp]*((s.empty())?i:i-s.top()-1);
        ma = max(area, ma);
    }
    return ma;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int ans = -1;
    int m = A[0].size();
    vector<int> temp(m,0);
    for(int i=0;i<A.size();i++) {
        vector<int> p = A[i];
        int j = 0;
        for(int k: p) {
            if(k==1) {
                temp[j++] += k;
            } else {
                temp[j++] = 0;
            }
        }
        ans = max(ans, largestRectangleArea(temp));
    }
    return ans;
}

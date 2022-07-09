int Solution::largestRectangleArea(vector<int> &A) {
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

int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> s;
    int max_area = -1;
    int i;
    while(i<A.size()){
        if(s.empty() || A[s.top()]<=A[i])
        s.push(i++);
        else{
            int t = s.top();
            s.pop();
            int area = A[t]*(s.empty()?i:(i-s.top()-1));
            max_area = max(max_area,area);
        }
    }
    while(!s.empty()){
        int t = s.top();
        s.pop();
        int area = A[t]*(s.empty()?i:(i-s.top()-1));
        max_area = max(max_area,area);
    }
    return max_area;
}

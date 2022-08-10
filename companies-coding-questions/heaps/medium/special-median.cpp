vector<double> findRunMed(vector<int> &A) {
    priority_queue<double> maxH;
    priority_queue<double, vector<double>, greater<double>> minH;
    vector<double> ans;
    double median = 0;
    for(int p : A) {
        double x = (double)p;
        if(minH.empty() and maxH.empty()) {
            maxH.push(x);
            median = x;
        } else if(minH.size() > maxH.size()) {
            if(x < median) {
                maxH.push(x);
            } else {
                maxH.push(minH.top());
                minH.pop();
                minH.push(x);
            }
            median = (maxH.top() + minH.top())/2;
        } else if(minH.size() < maxH.size()) {
            if(x > median) {
                minH.push(x);
            } else {
                minH.push(maxH.top());
                maxH.pop();
                maxH.push(x);
            }
            median = (maxH.top() + minH.top())/2;
        } else {
            if(x>median) {
                minH.push(x);
                median = minH.top();
            } else {
                maxH.push(x);
                median = maxH.top();
            }
        }
        ans.push_back(median);
    }
    return ans;
}
int Solution::solve(vector<int> &A) {
    auto fM = findRunMed(A);
    reverse(A.begin(), A.end());
    auto sM = findRunMed(A);
    reverse(A.begin(), A.end());
    int n = A.size();
    for(int i=0;i<n;i++) {
        double x = (double)A[i];
        if(i==0) {
            if(sM[n-2] == x)
                return 1;
        } else if(i==n-1) {
            if(fM[i-1]==x) {
                return 1;
            }
        } else {
            if(fM[i-1]==x or sM[n-i-2]==x)
                return 1;
        }
    }
    return 0;
}

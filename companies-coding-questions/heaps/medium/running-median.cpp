vector<int> Solution::solve(vector<int> &A) {
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    vector<int> ans;
    int median = 0;
    for(int x : A) {
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
            median = maxH.top();
        } else if(minH.size() < maxH.size()) {
            if(x > median) {
                minH.push(x);
            } else {
                minH.push(maxH.top());
                maxH.pop();
                maxH.push(x);
            }
            median = maxH.top();
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

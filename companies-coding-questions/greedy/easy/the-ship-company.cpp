vector<int> Solution::solve(int A, int B, vector<int> &C) {
    vector<int> temp = C;
    sort(temp.begin(), temp.end(), [](int a, int b) {
        return a>b;
    });
    int maxi = 0;
    for(int i=0;i<A;i++) {
        maxi += temp[0];
        temp[0]--;
        sort(temp.begin(), temp.end(), [](int a, int b) {
            return a>b;
        });
    }
    temp = C;
    sort(temp.begin(), temp.end());
    int mini = 0;
    for(int i=0;i<A;i++) {
        mini += temp[0];
        temp[0]--;
        if(temp[0]==0) {
            temp.erase(temp.begin());
        }
        sort(temp.begin(), temp.end());
    }
    return {maxi, mini};
}
